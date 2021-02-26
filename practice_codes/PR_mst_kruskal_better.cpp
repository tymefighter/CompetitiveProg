#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
    int u, v, w;

    Edge():
        u(0),
        v(0),
        w(0) {}

    Edge(int u_, int v_, int w_):
        u(u_),
        v(v_),
        w(w_) {}

    ~Edge() {}

    const Edge& operator= (const Edge &e) {
        u = e.u;
        v = e.v;
        w = e.w;
        return *this;
    }

    inline bool operator< (const Edge &e) const {
        return w < e.w;
    }
};

class UnionFind {
    private:
        int n;
        vector<int> rank, p;
    public:

        UnionFind (int n_):
            n(n_),
            rank(n, 0),
            p(n) {
                for(int i = 0;i < n;i++)
                    p[i] = i;
            }

        ~UnionFind () {}

        int findSet(int x) {
            int u, repx = x;

            while(p[repx] != repx)
                repx = p[repx];

            while(p[x] != x) {
                u = p[x];
                p[x] = repx;
                x = u;
            }

            return repx;
        }

        inline bool isSameSet (int u, int v) {
            return findSet(u) == findSet(v);
        }

        void unionSet (int u, int v) {
            u = findSet(u);
            v = findSet(v);
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

void readInput (int &n, vector<Edge> &edges) {
    int m;
    cin >> n >> m;
    edges.clear();
    edges.resize(m);

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }
}

void getMST (int n, vector<Edge> &edges) {
    UnionFind ufds(n);
    sort(edges.begin(), edges.end());
    int totalWt = 0;

    for(const Edge &e : edges) {
        if(!ufds.isSameSet(e.u, e.v)) {
            cout << "(" << e.u << ", " << e.v << ")\n";
            totalWt += e.w;
            ufds.unionSet(e.u, e.v);
        }
    }

    cout << "Total Weight: " << totalWt << "\n";
}

int main () {

    int n;
    vector<Edge> edges;

    readInput(n, edges);
    getMST(n, edges);

    return 0;
}
