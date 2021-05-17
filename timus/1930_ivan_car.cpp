#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e7;
int n, m, s, t;
vector<vector<pair<int, int> > > a;

void read() {
    cin >> n >> m;

    a.clear();
    a.resize(n);

    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        a[u].push_back({v, 1});
        a[v].push_back({u, 0});
    }

    cin >> s >> t;
    s --, t --;
}

void solve() {
    vector<vector<int> > d(n, vector<int>(2, INF));
    priority_queue<pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > > > pq;

    d[s][0] = d[s][1] = 0;
    pq.push({0, {s, 0}});
    pq.push({0, {s, 1}});

    while(!pq.empty()) {
        pair<int, pair<int, int> > dist_vert = pq.top();
        pq.pop();

        if(dist_vert.second.first == t) break;

        pair<int, int> u = dist_vert.second;
        if(d[u.first][u.second] < dist_vert.first) continue;

        for(pair<int, int> v : a[u.first]) {
            int w = u.second == v.second ? 0 : 1;
            if(d[u.first][u.second] + w < d[v.first][v.second]) {
                d[v.first][v.second] = d[u.first][u.second] + w;
                pq.push({d[v.first][v.second], v});
            }
        }
    }

    cout << min(d[t][0], d[t][1]) << "\n";
}

int main() {

    enable_fast_io();

    read();
    solve();

    return 0;
}