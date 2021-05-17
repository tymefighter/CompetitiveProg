#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long INF = 1e17;

int n, s, t;
vector<vector<pair<int, int> > > a;
map<string, int> name2node;

void read() {
    cin >> n;

    a.clear();
    a.resize(n);
    name2node.clear();

    for(int i = 0;i < n;i++) {
        string name;
        cin >> name;

        name2node[name] = i;

        int num_nbr;
        cin >> num_nbr;

        while(num_nbr --) {
            int j, w;
            cin >> j >> w;

            j --;
            a[i].push_back({j, w});
            a[j].push_back({i, w});
        }
    }
}

long long dijkstra(int s, int t) {
    vector<long long> d(n, INF);
    priority_queue<pair<int, int>, 
        vector<pair<int, int> >, 
        greater<pair<int, int> > > pq;

    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        pair<int, int> dist_vert = pq.top();
        pq.pop();
        
        int u = dist_vert.second;
        if(u == t || d[u] == INF) break;
        if(d[u] < dist_vert.first) continue;
        
        for(pair<int, int> v : a[u]) {
            if(d[u] + v.second < d[v.first]) {
                d[v.first] = d[u] + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }
    
    return d[t];
}

void solve() {
    int num_queries;
    cin >> num_queries;

    while(num_queries --) {
        string source, dest;
        cin >> source >> dest;

        cout << dijkstra(name2node[source], name2node[dest]) << "\n";
    } 
}

int main() {

    enable_fast_io();

    int s;
    cin >> s;

    while(s --) {
        read();
        solve();
    }

    return 0;
}