#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class UnionFind {
    private:
        int n;
        vector<int> rank, p;
    public:
        UnionFind(int n_):
            n(n_),
            rank(n, 0),
            p(n) {
                for(int i = 0;i < n;i++)
                    p[i] = i;
            }

        ~UnionFind() {}

        int findSet(int x) {
            int u, repx = x;

            while(p[repx] != repx)
                repx = p[repx];

            // path compression
            while(p[x] != x) {
                u = p[x];
                p[x] = repx;
                x = u;
            }

            return repx;
        }

        inline bool isSame(int u, int v) {return findSet(u) == findSet(v);}

        void unionSet(int u, int v) {
            u = findSet(u), v = findSet(v);

            if(u == v)
                return;

            if(rank[u] > rank[v])
                p[v] = u;
            else if(rank[u] < rank[v])
                p[u] = v;
            else {
                p[v] = u;
                rank[u] ++;
            }
        }
};

struct Edge {
    int u, v, w;
    Edge(int u_, int v_, int w_):
        u(u_),
        v(v_),
        w(w_) {}

    ~Edge() {}
};

bool comp(const Edge &e1, const Edge &e2) {return e1.w < e2.w;}

const int N = 300;
int n, m, arr[N][N];

int numNodes;
vector<Edge> elist;
vector<vector<pair<int, int> > > a;

inline int two2one(int r, int c) {
    return n * r + c;
}

void readInput() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
}

void build_edge_list() {
    elist.clear();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(i + 1 < n)
                elist.push_back(Edge(two2one(i, j), two2one(i + 1, j), abs(arr[i + 1][j] - arr[i][j])));
            
            if(j + 1 < m)
                elist.push_back(Edge(two2one(i, j), two2one(i, j + 1), abs(arr[i][j + 1] - arr[i][j])));
        }
    }
}

void build_mst() {
    numNodes = n * m;
    a.clear();
    a.resize(numNodes);

    UnionFind ufds(numNodes);
    sort(elist.begin(), elist.end(), comp);

    for(auto e : elist) {
        if(!ufds.isSame(e.u, e.v)) {
            ufds.unionSet(e.u, e.v);
            a[e.u].push_back({e.v, e.w});
            a[e.v].push_back({e.u, e.w});
        }
    }
}

pair<int, bool> dfs(int u, int parent, const int &t) {
    if(u == t)
        return {0, true};

    for(pair<int, int> v : a[u]) {
        if(v.first == parent)
            continue;

        pair<int, bool> ret_child = dfs(v.first, u, t);
        if(ret_child.second)
            return {max(ret_child.first, v.second), true};
    }

    return {0, false};
}

void solve() {
    build_edge_list();
    build_mst();

    cout << dfs(0, -1, two2one(n - 1, m - 1)).first << "\n";
}

int main() {

    readInput();
    solve();

    return 0;
}