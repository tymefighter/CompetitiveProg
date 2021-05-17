#include <iostream>
#include <queue>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 2000;
int n, m, w, a[N][N];

void read() {
    cin >> n >> m >> w;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
}

long long ds[N][N], dt[N][N];

void bfs(int si, int sj, long long (&d) [N][N]) {

    static int ar[] = {-1, 1, 0, 0};
    static int ac[] = {0, 0, -1, 1};

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            d[i][j] = -1;

    queue<pair<int, int> > q;
    d[si][sj] = 0;
    q.push({si, sj});

    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        for(int k = 0;k < 4;k++) {
            pair<int, int> v = {u.first + ar[k], u.second + ac[k]};

            if(v.first >= 0 && v.first < n 
                && v.second >= 0 && v.second < m
                && a[v.first][v.second] != -1
                && d[v.first][v.second] == -1) {
                    d[v.first][v.second] = d[u.first][u.second] + w;
                    q.push(v);
                }
        }
    }
}

void solve() {
    bfs(0, 0, ds);
    bfs(n - 1, m - 1, dt);

    long long ans = ds[n - 1][m - 1];
    long long min_dist_to_teleport = -1, min_dist_from_teleport = -1;
    pair<int, int> to_index, from_index;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] <= 0) continue;

            long long dist_to_teleport = ds[i][j] + a[i][j];
            long long dist_from_teleport = dt[i][j] + a[i][j];

            if(ds[i][j] != -1 &&
                (min_dist_to_teleport == -1 || 
                    dist_to_teleport < min_dist_to_teleport))
                min_dist_to_teleport = dist_to_teleport;

            if(dt[i][j] != -1 &&
                (min_dist_from_teleport == -1 ||
                    dist_from_teleport < min_dist_from_teleport))
                min_dist_from_teleport = dist_from_teleport;
        }
    }

    if(min_dist_from_teleport != -1 && min_dist_to_teleport != -1 && 
        (ans == -1 ||
            min_dist_from_teleport + min_dist_to_teleport < ans))
        ans = min_dist_from_teleport + min_dist_to_teleport;

    cout << ans << "\n";
}

int main() {
    enable_fast_io();

    read();
    solve();

    return 0;
}