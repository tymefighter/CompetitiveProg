#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long INF = 1e17;
const int N = 100;

int n;
long long a[N][N];

void read() {
    int m;
    cin >> m;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            a[i][j] = INF;

    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        a[v][u] = a[u][v] = min(a[u][v], (long long) w);
    }
}

int p[N][N];
long long d[N][N];

void fw(int idx) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            d[i][j] = a[i][j];
            p[i][j] = (a[i][j] == INF ? -1 : i);
        }
    }   

    for(int k = 0;k < n;k++) {
        if(k == idx) continue;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

void get_path(vector<int> &path, int u, int v) {
    if(v == u) {
        path.push_back(u + 1);
        return;
    }

    get_path(path, u, p[u][v]);
    path.push_back(v + 1);
}

void solve() {
    long long best_value = INF;
    vector<int> best_path;

    for(int i = 0;i < n;i++) {
        fw(i);

        int u = -1, v = -1;
        long long value = INF;

        for(int j = 0;j < n;j++) {
            if(a[i][j] == INF) continue;

            for(int k = j + 1;k < n;k++) {
                if(a[i][k] == INF) continue;

                if(a[i][j] + d[j][k] + a[k][i] < value) {
                    u = j;
                    v = k;
                    value = a[i][j] + d[j][k] + a[k][i];
                }
            }
        }

        if(value < best_value) {
            best_path.clear();
            best_path.push_back(i + 1);
            get_path(best_path, u, v);
            best_value = value;
        }
    }

    if(best_value == INF) cout << "No solution.\n";
    else {
        for(int x : best_path) cout << x << " ";
        cout << "\n"; 
    }
}

int main() {

    enable_fast_io();

    while(cin >> n) {
        if(n == -1) break;

        read();
        solve();
    }
    return 0;
}