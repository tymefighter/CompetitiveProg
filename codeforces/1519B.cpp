#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100, K = 10000;
bool dp[N][N][K];

void compute_dp() {
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            for(int k = 0;k < K;k++)
                dp[i][j][k] = false;

    dp[0][0][0] = true;

    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            for(int k = 0;k < K;k++) {
                if(i + 1 < N && k + j + 1 < K) dp[i + 1][j][k + j + 1] |= dp[i][j][k];
                if(j + 1 < N && k + i + 1 < K) dp[i][j + 1][k + i + 1] |= dp[i][j][k];
            }
        }
    }
}

void solve() {
    int t;
    cin >> t;

    while(t --) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << (dp[n - 1][m - 1][k] ? "YES" : "NO") << "\n";
    }
}

int main() {

    enable_fast_io();

    compute_dp();
    solve();

    return 0;
}