#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Solution Explanation
 * 
 * Denote: dist(u, v) as the shortest distance between
 * vertices u and v
 * 
 * Define: Distance from a shortest path P to a vertex
 * u is the minimum distance between a vertex in P and u.
 * Formally,
 * dist(P, u) = min over p in P {dist(p, u)}
 * 
 * Problem: Over all shortest paths between s and f,
 * we have to compute the maximum distance from
 * the shortest path to r. Formally,
 * answer = max over all shortest paths P between s and f {dist(P, r)}
 * 
 * We can compute this as follow,
 * 
 * Denote: max_over_min(u): max over all shortest paths P between
 * u and f {dist(P, r)}
 * 
 * For each vertex u in V(G) (vertex set of the input graph),
 * 
 * max_over_min(u) = max over all v such that (u, v) is an edge
 * along a shortest path from u to f {min {d(u, r), max_over_min(v)}}
 * 
 * I don't have a completely formal proof for this...
 * 
 */

const int INF = static_cast<int>(1e8);

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(
    vector<vector<int> > &a,
    int &s, int &f, int &r
) {
    int n, m;
    cin >> n >> m;

    a.resize(n);

    while(m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cin >> s >> f >> r;
    s --, f --, r --;
}

vector<int> bfs(
    const vector<vector<int> > &a,
    const int s
) {
    int n = a.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : a[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int compute_max_over_min(
    const vector<vector<int> > &a,
    const int s, const int f, const int r
) {
    int n = a.size();
    vector<int> dist_f = bfs(a, f);
    vector<int> dist_r = bfs(a, r);

    queue<int> q;
    vector<bool> placed_in_queue(n, false);
    vector<int> max_over_min(n, -1);

    placed_in_queue[f] = true;
    max_over_min[f] = dist_r[f];
    for(int v : a[f]) {
        q.push(v);
        placed_in_queue[v] = true;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        max_over_min[u] = -INF;
        for(int v : a[u]) {
            if(dist_f[u] == dist_f[v] + 1)
                max_over_min[u] = max(max_over_min[u], min(dist_r[u], max_over_min[v]));
        }

        for(int v : a[u]) {
            if(!placed_in_queue[v]) {
                q.push(v);
                placed_in_queue[v] = true;
            }
        }
    }

    return max_over_min[s];
}

int main() {

    enable_fast_io();

    vector<vector<int> > a;
    int s, f, r;

    read_input(a, s, f, r);
    cout << compute_max_over_min(a, s, f, r) << "\n";

    return 0;
}