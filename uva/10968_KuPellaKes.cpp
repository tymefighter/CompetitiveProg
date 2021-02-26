#include <iostream>
#include <vector>
#include <queue>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

inline bool is_odd(int n) {return (n & 1) != 0;}

bool read_input(vector<vector<int> > &a, int &s, int &t) {
    int n, m;

    cin >> n >> m;
    if((n | m) == 0) return false;

    a.resize(n);

    vector<int> degree(n, 0);

    while(m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        a[u].push_back(v);
        a[v].push_back(u);

        degree[u] ++;
        degree[v] ++;
    }

    s = t = -1;
    for(int u = 0;u < n;u++) {
        if(is_odd(degree[u])) {
            if(s == -1) s = u;
            else {
                t = u;
                break;
            }
        }
    }

    return true;
}

int compute_min_roads(
    const vector<vector<int> > &a,
    const int s, const int t
) {
    const int n = a.size();
    queue<int> q;
    vector<int> dist(n, -1);

    dist[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == t) break;

        for(int v : a[u]) {
            if((v == t || a[v].size() > 2) && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[t];
}

int main() {

    enable_fast_io();
    
    while(true) {
        vector<vector<int> > a;
        int s, t;

        if(!read_input(a, s, t)) break;
        printf("%d\n", compute_min_roads(a, s, t));
    }

    return 0;
}