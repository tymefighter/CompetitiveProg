#include <iostream>
#include <stack>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Edge {
    int u, v;
    long long w;

    Edge(int u_, int v_, long long w_):
        u(u_), v(v_), w(w_) {}

    Edge() {}
};

const int M = 5000, N = 2500;
int n, m;
Edge edge_list[M];

void read() {
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u --, v --;
        edge_list[i] = Edge(u, v, w);
    }
}

int p[N];
long long d[N];

void solve() {
    for(int i = 0;i < n;i++) {
        p[i] = -1;
        d[i] = 0;
    }

    int last_relaxed_node;
    for(int i = 0;i < n;i++) {
        last_relaxed_node = -1;

        for(int j = 0;j < m;j++) {
            if(d[edge_list[j].u] + edge_list[j].w < d[edge_list[j].v]) {
                d[edge_list[j].v] = d[edge_list[j].u] + edge_list[j].w;
                p[edge_list[j].v] = edge_list[j].u;
                last_relaxed_node = edge_list[j].v;
            }
        }
    }

    if(last_relaxed_node == -1) {
        cout << "NO\n";
        return;
    }

    int start_vert = last_relaxed_node;
    for(int i = 0;i < n;i++) start_vert = p[start_vert];

    stack<int> path;

    path.push(start_vert);
    for(int cycle_vert = p[start_vert];
        cycle_vert != start_vert; 
        cycle_vert = p[cycle_vert]) path.push(cycle_vert);
    path.push(start_vert);

    cout << "YES\n";
    while(!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
    cout << "\n";
}

int main() {
    enable_fast_io();

    read();
    solve();

    return 0;
}

