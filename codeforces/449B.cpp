#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct EdgeTo {
    int v, w;
    bool deletable;

    EdgeTo(int v_, int w_, bool deletable_ = false):
        v(v_), w(w_), deletable(deletable_) {}
};

const int N = 100000;
int n;
vector<vector<EdgeTo> > a;

void read() {
    int m, k;
    cin >> n >> m >> k;
    a.clear();
    a.resize(n);

    while(m --) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        
        a[u].push_back(EdgeTo(v, w));
        a[v].push_back(EdgeTo(u, w));
    }

    while(k --) {
        int s, y;
        cin >> s >> y;
        s --;

        a[0].push_back(EdgeTo(s, y, true));
    }
}

const long long INF = 1e17;
long long d[N];

void dijkstra() {
    for(int i = 0;i < n;i++) d[i] = INF;
    priority_queue<pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> > > pq;

    d[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        pair<int, int> dist_vert = pq.top();
        pq.pop();

        if(d[dist_vert.second] == INF) break;
        if(d[dist_vert.second] < dist_vert.first) continue;
        int u = dist_vert.second;

        for(EdgeTo &to : a[u]) {
            if(d[u] + to.w < d[to.v]) {
                d[to.v] = d[u] + to.w;
                pq.push({d[to.v], to.v});
            }
        }
    }
}

int indeg[N];

void solve() {
    dijkstra();

    for(int u = 0;u < n;u++) indeg[u] = 0;

    int num_del = 0;
    for(int u = 0;u < n;u++) {
        for(EdgeTo &to : a[u]) {
            if(d[u] + to.w == d[to.v]) indeg[to.v] ++;
            else if(to.deletable) num_del ++;
        }
    }

    for(int u = 0;u < n;u++) {
        for(EdgeTo &to : a[u]) {
            if(d[u] + to.w == d[to.v] && to.deletable && indeg[to.v] > 1) {
                indeg[to.v] --;
                num_del ++;
            }
        }
    }

    cout << num_del << "\n";
}

int main() {

    enable_fast_io();

    read();
    solve();

    return 0;
}