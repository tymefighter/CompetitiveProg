#include<iostream>
#include<vector>

using namespace std;

static void run_with_stack_size(void (*func)(), size_t stsize) {
    char *stack, *send;
    stack=(char *)malloc(stsize);
    send=stack+stsize-16;
    send=(char *)((uintptr_t)send/16*16);
    asm volatile(
      "mov %%rsp, (%0)\n"
      "mov %0, %%rsp\n"
      :
      : "r" (send));
    func();
    asm volatile(
      "mov (%0), %%rsp\n"
      :
      : "r" (send));
    free(stack);
}

const long long INF =
    static_cast<long long>(1e17 + 5);

class SegmentTree {
    private:
        int n;
        vector<long long> t, lazy;
        vector<long long> minCost; // segment tree on cost (static)

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void buildTree(long long c[], int reMapPath[], int p, int L, int R) {
            if(L == R) {
                t[p] = INF;     // initialize with infinity
                lazy[p] = -1;   // no lazy update to be done
                minCost[p] = c[reMapPath[L]];  // min cost
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(c, reMapPath, left(p), L, mid);
            buildTree(c, reMapPath, right(p), mid + 1, R);

            t[p] = INF;
            lazy[p] = -1;
            minCost[p] = min(minCost[left(p)], minCost[right(p)]);
        }

        // if lazy update at p was remaining, then do it and
        // push lazy update below
        void propagate(int p, int L, int R) {
            if(lazy[p] != -1) {
                long long costWithFullTank = lazy[p] + minCost[p];
                t[p] = min(t[p], costWithFullTank);

                if(L != R) {
                    if(lazy[left(p)] == -1 || lazy[p] < lazy[left(p)])
                        lazy[left(p)] = lazy[p];

                    if(lazy[right(p)] == -1 || lazy[p] < lazy[right(p)])
                        lazy[right(p)] = lazy[p];
                }

                lazy[p] = -1;
            }
        }

        void updateRange(int p, int L, int R, int l, int r, long long x) {

            if(l == L && R == r) {
                if(lazy[p] == -1 || x < lazy[p])
                    lazy[p] = x;

                propagate(p, L, R);

                return;
            }

            propagate(p, L, R);

            int mid = (L + R) >> 1;
            if(r <= mid)
                updateRange(left(p), L, mid, l, r, x);
            else if(l >= mid + 1)
                updateRange(right(p), mid + 1, R, l, r, x);
            else {
                updateRange(left(p), L, mid, l, mid, x);
                updateRange(right(p), mid + 1, R, mid + 1, r, x);
            }
            
            t[p] = min(t[left(p)], t[right(p)]);
        }

        long long rangeMin(int p, int L, int R, int l, int r) {
            propagate(p, L, R);

            if(l == L && R == r)
                return t[p];

            int mid = (L + R) >> 1;
            if(r <= mid)    
                return rangeMin(left(p), L, mid, l, r);
            else if(l >= mid + 1)
                return rangeMin(right(p), mid + 1, R, l, r);
            else
                return min (
                    rangeMin(left(p), L, mid, l, mid),
                    rangeMin(right(p), mid + 1, R, mid + 1, r)
                );
        }

    public:

        SegmentTree(int n_, long long c[], int reMapPath[]):
            n(n_),
            t(4 * n),
            lazy(4 * n),
            minCost(4 * n) {
                buildTree(c, reMapPath, 1, 0, n - 1);
            }

        ~SegmentTree() {}

        inline void updateRange(int l, int r, long long x) {
            updateRange(1, 0, n - 1, l, r, x);
        }

        inline long long rangeMin(int l, int r) {
            return rangeMin(1, 0, n - 1, l, r);
        }
};

const int N = 1000005;

int n, s, t;
long long m, p[N], c[N], pathLength;
int mapPath[N], reMapPath[N];
vector<vector<int> > a;

void readInput() {
    scanf("%d %lld %d %d ", &n, &m, &s, &t);
    s --, t --;

    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++) {
        scanf("%lld %lld ", &p[i], &c[i]);
        if(i) {
            p[i] --;
            a[i].push_back(p[i]);
            a[p[i]].push_back(i);
        }
        c[i] = (c[i] == 0 ? INF : c[i]); // make unrefuellable costs as INF
        reMapPath[i] = mapPath[i] = -1;
    }
    c[t] = c[s] = 0;
}

int dfsGetPath(int u, int parent) {
    if(u == s) {
        mapPath[u] = 0;
        reMapPath[0] = u;
        return 0;
    }

    for(int v : a[u]) {
        if(v == parent)
            continue;

        int val = dfsGetPath(v, u);
        if(val != -1) {
            mapPath[u] = val + 1;
            reMapPath[val + 1] = u;
            return mapPath[u];
        }
    }

    return -1;
}

void dfsNonPath(
    SegmentTree &st,
    int u,
    int parent,
    int distance,
    int pathAncestor
) {
    for(int v : a[u]) {
        if(v == parent)
            continue;

        dfsNonPath(st, v, u, distance + 1, pathAncestor);
    }

    long long i = mapPath[pathAncestor];
    long long low = max(i - (m - distance), 0ll);
    long long high = min(i - 1, pathLength - 1);

    if(c[u] == INF || low > high)
        return;

    cout << st.rangeMin(low, high) + c[u] << "--\n";
    long long cost = st.rangeMin(low, high) + c[u];

    low = max(i, 0ll);
    high = min(i + m - distance, pathLength - 1);

    cout << u << " " << low << " " << high << " " << cost << " " << pathLength - 1 << "--\n";

    if(low <= high) {
        cout << st.rangeMin(low, high) << " " << cost << "|||}\n";
        st.updateRange(low, high, cost);
        cout << st.rangeMin(low, high) << "||\n";
        cout << u << " " << low << " " << high << " " << cost << " " << pathLength - 1 << "--\n";
    }
}

void dfsPath(SegmentTree &st, int u, int parent) {
    if(u == s) {
        st.updateRange(0, 0, 0); // mapPath[s] = 0
    }
    else {
        for(int v : a[u]) {
            if(v != parent && mapPath[v] != -1) {
                dfsPath(st, v, u);
                break;
            }
        }

        for(int v : a[u]) {
            if(v != parent && mapPath[v] == -1)
                dfsNonPath(st, v, u, 1, u);
        }
    }

    long long low = mapPath[u] + 1, high = min(mapPath[u] + m, pathLength - 1);
    if(low <= high) {
        st.updateRange(low, high, st.rangeMin(mapPath[u], mapPath[u]));
    }
}

void solve() {
    pathLength = dfsGetPath(t, -1) + 1;
    SegmentTree st(n, c, reMapPath); // this models the dp array
    // st[mapPath[i]]: if i is along path from s to t, then
    // st[mapPath[i]] denotes the minimum cost to reach i from s
    // and have full tank

    dfsPath(st, t, -1);

    long long val = st.rangeMin(pathLength - 1, pathLength - 1);
    if(val >= INF)
        printf("-1\n");
    else
        printf("%lld\n", val);


    cout << st.rangeMin(55, 115) << " " << st.rangeMin(55, 124) << " " << st.rangeMin(55, 68) << "||\n"; 
}

void main2() {

    int t;
    scanf("%d ", &t);

    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: ", i);
        solve();
    }
}

int main() {
    run_with_stack_size(main2, 4*64*1024*1024);
    return 0;
}