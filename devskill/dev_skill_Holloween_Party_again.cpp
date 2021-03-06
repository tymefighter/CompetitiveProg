#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1000;
int n, m;
char dress[N][N];
int dist[N][N];

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input() {
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> dress[i][j];
            dist[i][j] = -1;
        }
    }
}

int solve() {
    static int ar[] = {0, 0, -1, 1};
    static int ac[] = {-1, 1, 0, 0};

    deque<pair<int, int> > dq;
    dist[0][0] = 0;
    dq.push_back({0, 0});

    while(!dq.empty()) {
        int r = dq.front().first;
        int c = dq.front().second;
        dq.pop_front();

        if(r == n - 1 && c == m - 1) return dist[r][c];

        for(int k = 0;k < 4;k++) {
            int r_next = r + ar[k], c_next = c + ac[k];

            if(r_next < 0 || r_next >= n
                || c_next < 0 || c_next >= m) continue;

            if(
                dress[r_next][c_next] == dress[r][c]
                && 
                (dist[r_next][c_next] == -1 
                || dist[r][c] < dist[r_next][c_next])
            ) {
                dist[r_next][c_next] = dist[r][c];
                dq.push_front({r_next, c_next});
            }
            else if(dist[r_next][c_next] == -1) {
                dist[r_next][c_next] = dist[r][c] + 1;
                dq.push_back({r_next, c_next});
            }
        }
    }

    return -1;
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    for(int test_num = 1;test_num <= t;test_num++) {
        read_input();

        cout << "Case " << test_num << ": " << solve() << "\n";
    }

    return 0;
}