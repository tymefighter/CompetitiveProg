#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100000;
int n, m, s, t;
vector<pair<pair<int, int>, int> > edge_list;
vector<vector<pair<int, int> > > g, g_rev;

void read() {
    cin >> n >> m >> s >> t;
    s --, t --;

    g.resize(n);
    g_rev.resize(n);
    edge_list.resize(m);

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        u --, v --;
        edge_list[i] = {{u, v}, w};
        g[u].push_back({v, w});
        g_rev[v].push_back({u, w});
    }
}

const long long INF = 1e17;

void dijkstra(
    vector<vector<pair<int, int> > > &a,
    vector<long long> &d, 
    int source
) {
    d.clear();
    d.assign(n, INF);

    priority_queue<pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> > > pq;

    d[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        pair<int, int> dist_vert = pq.top();
        pq.pop();

        if(d[dist_vert.second] == INF) break;
        if(d[dist_vert.second] < dist_vert.first) continue;
        int u = dist_vert.second;

        for(pair<int, int> v : a[u]) {
            if(d[u] + v.second < d[v.first]) {
                d[v.first] = d[u] + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }
}

void solve() {
    vector<long long> ds, dt;
    dijkstra(g, ds, s);
    dijkstra(g_rev, dt, t);

    vector<pair<pair<long long, long long>, int> > ranges;
    vector<bool> is_yes(m, true);

    for(int i = 0;i < m;i++) {
        int u = edge_list[i].first.first;
        int v = edge_list[i].first.second;
        int w = edge_list[i].second;

        if(ds[u] + w + dt[v] == ds[t]) ranges.push_back({{ds[u], ds[v]}, i});
        else is_yes[i] = false;
    }

    sort(ranges.begin(), ranges.end());
    int idx_of_right = 0;

    for(int i = 1;i < ranges.size();i++) {
        if(ranges[idx_of_right].first.second > ranges[i].first.first)
            is_yes[ranges[i].second] = is_yes[ranges[idx_of_right].second] = false;
        
        if(ranges[idx_of_right].first.second < ranges[i].first.second)
            idx_of_right = i;
    }

    for(int i = 0;i < m;i++) {
        int u = edge_list[i].first.first;
        int v = edge_list[i].first.second;
        int w = edge_list[i].second;

        if(is_yes[i]) cout << "YES\n";
        else if(ds[t] > 1 +  ds[u] + dt[v]) 
            cout << "CAN " << w - (ds[t] - 1 - ds[u] - dt[v]) << "\n";
        else cout << "NO\n";
    }
}

int main() {

    enable_fast_io();
    read();
    solve();

    return 0;
}