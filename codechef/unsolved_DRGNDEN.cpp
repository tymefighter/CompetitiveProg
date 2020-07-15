#include<iostream>
#include<cassert>
#include<vector>
#include<queue>

using namespace std;

const int N = 200005;
int n, q, hNormal[N], aNormal[N];
int hRev[N], aRev[N];

vector<vector<pair<int, long long> > > tNormal, tRev;
// for L, R it stores info about all elements which
// are greater than all others towards it's left
// the information is their heights in sorted order
// and prefix sums of values

inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}

void buildTree(
    vector<vector<pair<int, long long> > > &t,
    int *a,
    int *h,
    int p,
    int L,
    int R
) {
    if(L == R) {
        t[p].push_back({h[L], a[L]});
        return;
    }

    int mid = (L + R) >> 1;
    buildTree(t, a, h, left(p), L, mid);
    buildTree(t, a, h, right(p), mid + 1, R);

    t[p] = t[left(p)];
    pair<int, long long> prev = 
        t[p][static_cast<int>(t[p].size()) - 1];
        // there is atleast one ele here

    const vector<pair<int, long long> > &b = t[right(p)];
    
    for(int i = 0;i < b.size();i++) {
        if(b[i].first > prev.first) {
            prev = {
                b[i].first,
                prev.second + (i > 0 ? b[i].second - b[i - 1].second : b[i].second)
            };
            t[p].push_back(prev);
        }
    }

    // cout << L << " " << R << "--\n";
    // for(pair<int, long long> x : t[p])
    //     cout << "(" << x.first << ", " << x.second << ") ";
    // cout << "\n";
}

void getAllRange(
    int p,
    int L,
    int R,
    int l,
    int r,
    vector<int> &idx
) {
    if(l == L && R == r) {
        idx.push_back(p);
        return;
    }

    int mid = (L + R) >> 1;

    if(r <= mid)
        getAllRange(left(p), L, mid, l, r, idx);
    else if(l >= mid + 1)
        getAllRange(right(p), mid + 1, R, l, r, idx);
    else {
        getAllRange(left(p), L, mid, l, mid, idx);
        getAllRange(right(p), mid + 1, R, mid + 1, r, idx);
    }
}

// check if curr is higher -- V.IMP !!!!

pair<int, long long> searchLeftMostLarger(
    const vector<pair<int, long long> > &a,
    int maxHt
) {
    int m = a.size();
    int low = 0, high = m - 1, ansIdx = m;

    while(low <= high) {
        int mid = (low + high) >> 1;
        if(a[mid].first > maxHt) {
            ansIdx = min(ansIdx, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    if(ansIdx == m)
        return {maxHt, 0};
    
    return {
        a[m - 1].first,
        a[m - 1].second - (ansIdx > 0 ? a[ansIdx - 1].second : 0)
    };
}

long long query(
    vector<vector<pair<int, long long> > > &t,
    int *a,
    int *h,
    int l,
    int r
) {

    if(l == r)
        return a[l];

    vector<int> idx;
    getAllRange(1, 0, n - 1, l, r - 1, idx);
    int maxHt = -1;
    long long ans = a[r];

    for(int i : idx) {
        const vector<pair<int, long long> > &a = t[i];
        pair<int, long long> val = searchLeftMostLarger(a, maxHt);
        ans += val.second;
        maxHt = val.first;
        if(maxHt >= h[r])
            return -1;
    }

    return ans;
}

void readInput() {
    scanf("%d %d ", &n, &q);
    for(int i = 0;i < n;i++) {
        scanf("%d ", &hNormal[i]);
        hRev[n - i - 1] = hNormal[i];
    }
    for(int i = 0;i < n;i++) {
        scanf("%d ", &aNormal[i]);
        aRev[n - i - 1] = aNormal[i];
    }
}

void preProcess() {
    tNormal.clear();
    tNormal.assign(4 * n, vector<pair<int, long long> >());
    tRev.clear();
    tRev.assign(4 * n, vector<pair<int, long long> >());
    buildTree(tNormal, aNormal, hNormal, 1, 0, n - 1);
    buildTree(tRev, aRev, hRev, 1, 0, n - 1);
}

void solve() {
    while(q --) {
        int qType, start, end;
        scanf("%d %d %d ", &qType, &start, &end);
        start --;
        end --;
        assert(qType == 2);

        if(start >= end)
            printf("%lld\n", query(tNormal, aNormal, hNormal, end, start));
        else
            printf("%lld\n", query(tRev, aRev, hRev, n - end - 1, n - start - 1));
    }
}

void solveSimple() {
    while(q --) {
        int qType;
        scanf("%d ", &qType);
        if(qType == 1) {
            int idx, val;
            scanf("%d %d ", &idx, &val);
            idx --;
            aNormal[idx] = val;
            aRev[n - idx - 1] = val;
        }
        else {
            int start, end;
            scanf("%d %d ", &start, &end);
            start --, end --;
            
            if(start == end) {
                printf("%d\n", aNormal[start]);
                continue;
            }
            
            priority_queue<pair<int, int> > pq;
            int *a;
            if(start < end) {
                bool foundGE = false;
                for(int i = start + 1;i <= end;i++) {
                    if(hNormal[i] >= hNormal[start]) {
                        foundGE = true;
                        break;
                    }
                }

                if(foundGE) {
                    printf("-1\n");
                    continue;
                }

                for(int i = start;i <= end;i++)
                    pq.push({hNormal[i], i});
                a = aNormal;
            }
            else {
                bool foundGE = false;
                for(int i = start - 1;i >= end;i--) {
                    if(hNormal[i] >= hNormal[start]) {
                        foundGE = true;
                        break;
                    }
                }

                if(foundGE) {
                    printf("-1\n");
                    continue;
                }


                for(int i = n - start - 1;i <= n - end - 1;i++) 
                    pq.push({hRev[i], i});
                a = aRev;
                end = n - end - 1;
            }

            long long ans = 0;
            int idx = -1;
            while(idx != end) {
                pair<int, int> p = pq.top();
                pq.pop();
                if(p.second < idx)
                    continue;
                idx = p.second;
                ans += a[idx];
            }

            printf("%lld\n", ans);
        }
    }
}

int main() {

    readInput();
    if(n <= 1000 && q <= 1000)
        solveSimple();
    else {
        preProcess();
        solve();
    }
    return 0;
}