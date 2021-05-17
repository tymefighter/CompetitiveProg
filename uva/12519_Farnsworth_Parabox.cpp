#include <iostream>

using namespace std;

struct Edge {
    int u, v, w;

    Edge() {}

    Edge(int u_, int v_, int w_):
        u(u_), v(v_), w(w_) {}
};

const int N = 100, M = 10000;
int n, m;
Edge edge_arr[M];
long long d[N];

void read() {
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        edge_arr[i] = Edge(u, v, w);
        edge_arr[i + m] = Edge(v, u, -w);
    }

    m += m;
}

void solve() {
    for(int i = 0;i < n;i++) d[i] = 0;

    bool relax_performed;
    for(int i = 0;i < n;i++) {
        relax_performed = false;

        for(int j = 0;j < m;j++) {
            if(d[edge_arr[j].u] + edge_arr[j].w < d[edge_arr[j].v]) {
                d[edge_arr[j].v] = d[edge_arr[j].u] + edge_arr[j].w;
                relax_performed = true;
            }
        }
    }

    if(relax_performed) cout << "Y\n";
    else cout << "N\n";
}

int main() {

    while(cin >> n >> m) {
        if(!(n | m)) break;

        read();
        solve();
    }


    return 0;
}