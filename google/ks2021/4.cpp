#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {

    private:

    int n;
    vector<int> rank, p;

    public:

    UnionFind(int n_):
        n(n_), rank(n, 0), p(n) {for(int i = 0;i < n;i++) p[i] = i;}

    int find_set(int x) {
        int repx = x;

        while(p[repx] != repx) repx = p[repx];

        while(p[x] != x) { // Path Compression
            int u = p[x];
            p[x] = repx;
            x = u;
        }

        return repx;
    }

    inline bool is_same(int u, int v) {return find_set(u) == find_set(v);}

    void union_set(int u, int v) {
        
        u = find_set(u), v = find_set(v);
        if(u == v) return;

        if(rank[u] > rank[v]) p[v] = u;
        else if(rank[u] < rank[v]) p[u] = v;
        else {
            p[v] = u;
            rank[u] ++;
        }
    }
};

const int N = 505;
int n, a[N][N], b[N][N];
vector<pair<int, pair<int, int> > > edges;

void read_input() {
    scanf("%d ", &n);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            scanf("%d ", &a[i][j]);

    edges.clear();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d ", &b[i][j]);
            if(a[i][j] == -1) edges.push_back({b[i][j], {i, n + j}});
        }
    }

    for(int i = 0;i < n;i++) scanf("%*d ");
    for(int i = 0;i < n;i++) scanf("%*d ");
}

long long get_min_wt() {
    long long removed_wt = 0;
    sort(edges.begin(), edges.end(), 
        greater<pair<int, pair<int, int> > >());

    UnionFind ufds(2 * n);

    for(auto &edge : edges) {
        if(!ufds.is_same(
            edge.second.first, edge.second.second
        )) ufds.union_set(edge.second.first, edge.second.second);
        else removed_wt += edge.first;
    }

    return removed_wt;
}

int main() {

    int t;
    scanf("%d ", &t);

    for(int tc = 1;tc <= t;tc++) {
        read_input();
        printf("Case #%d: %lld\n", tc, get_min_wt());
    }

    return 0;
}