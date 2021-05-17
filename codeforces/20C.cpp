#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long INF = 1e17;

int n, m;
vector<vector<pair<int, int> > > a;

void read() {
    cin >> n >> m;

    a.clear();
    a.resize(n);

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

void print_path(vector<int> &p, int s, int u) {
    if(u == s) {
        cout << s + 1 << " ";
        return;
    }

    print_path(p, s, p[u]);
    cout << u + 1 << " ";
}

void solve() {
    vector<long long> d(n, INF);
    vector<int> p(n, -1);
    priority_queue<pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> > > pq;

    d[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        pair<int, int> dist_vert = pq.top();
        pq.pop();

        int u = dist_vert.second;
        if(u == n - 1 || d[u] == INF) break;
        if(d[u] < dist_vert.first) continue;

        for(pair<int, int> v : a[u]) {
            if(d[u] + v.second < d[v.first]) {
                d[v.first] = d[u] + v.second;
                p[v.first] = u;
                pq.push({d[v.first], v.first});
            }
        }
    }

    if(d[n - 1] == INF) cout << "-1\n";
    else {
        print_path(p, 0, n - 1); 
        cout << "\n";
    }
}

int main() {
    enable_fast_io();

    read();
    solve();

    return 0;
}