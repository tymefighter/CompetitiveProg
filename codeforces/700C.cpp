#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

const long long INF = 1000000000000000;
const int N = 1000;
int n, m, s, t;
vector<Edge> edges;
vector<vector<int> > a;

void read_input() {
    scanf("%d %d %d %d ", &n, &m, &s, &t);
    s --, t --;

    a.clear();
    a.resize(n);
    edges.clear();
    edges.resize(m);

    for(int i = 0;i < m;i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld ", &u, &v, &w);

        u --, v --;
        edges[i] = {u, v, w};
        a[u].push_back(i);
        a[v].push_back(i);
    }
}

bool visited[N];
int pred[N];
vector<int> path;

inline int get_other(int edge_idx, int u) {
    return (edges[edge_idx].u != u ? edges[edge_idx].u : edges[edge_idx].v);
}

void dfs_get_path(int u, int parent_edge) {
    visited[u] = true;
    pred[u] = parent_edge;

    if(u == t) return;

    for(int edge_idx : a[u]) {
        int v = get_other(edge_idx, u);
        if(!visited[v]) dfs_get_path(v, edge_idx);
    }
}

void get_path(int u) {
    if(u == s) return;

    get_path(get_other(pred[u], u));
    path.push_back(pred[u]);
}

bool desc_t[N];

bool get_desc(int u, int broken_edge) {
    visited[u] = true;

    if(u == t) {
        desc_t[u] = true;
        return true;
    }

    desc_t[u] = false;
    for(int edge_idx : a[u]) {
        if(edge_idx == broken_edge) continue;

        int v = get_other(edge_idx, u);

        if(!visited[v])
            desc_t[u] |= get_desc(v, broken_edge);
    }

    return desc_t[u];
}

int tin[N], low[N], timer;
vector<int> bridges;

void find_bridge(int u, int parent_edge, int broken_edge) {
    tin[u] = low[u] = timer ++;

    for(int edge_idx : a[u]) {
        if(edge_idx == parent_edge || edge_idx == broken_edge) continue;

        int v = get_other(edge_idx, u);

        if(tin[v] == -1) {
            find_bridge(v, edge_idx, broken_edge);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u] && desc_t[v])
                bridges.push_back(edge_idx);
        }
        else
            low[u] = min(low[u], tin[v]);
    }
}

vector<int> ans;

long long solve() {
    for(int i = 0;i < n;i++) {
        visited[i] = false;
        pred[i] = -1;
    }

    dfs_get_path(s, -1);
    if(!visited[t]) return 0;

    get_path(t);

    long long min_val = INF;

    ans.clear();
    for(int broken_edge : path) {
        for(int i = 0;i < n;i++) {
            low[i] = tin[i] = -1;
            visited[i] = false;
            desc_t[i] = false;
        }

        vector<int> curr(1, broken_edge);

        get_desc(s, broken_edge);
        if(!visited[t]) {
            if(edges[broken_edge].w < min_val) {
                ans = curr;
                min_val = edges[broken_edge].w;
            }   
            continue;
        }

        timer = 0;
        bridges.clear();
        find_bridge(s, -1, broken_edge);

        long long curr_min = INF;
        int min_edge_idx = -1;
        for(int edge_idx : bridges) {
            if(edges[edge_idx].w < curr_min) {
                min_edge_idx = edge_idx;
                curr_min = edges[edge_idx].w;
            }
        }

        curr.push_back(min_edge_idx);
        curr_min += edges[broken_edge].w;
        if(curr_min < min_val) {
            ans = curr;
            min_val = curr_min;
        }
    }

    return min_val;
}

int main() {

    read_input();
    long long result = solve();
    if(result == INF) {
        printf("-1\n");
        return 0;
    }

    printf("%lld\n", result);
    printf("%d\n", ans.size());
    for(int idx : ans)
        printf("%d ", idx + 1);
    printf("\n");

    return 0;
}