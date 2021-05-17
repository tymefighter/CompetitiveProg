#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long INF = 1e17;
const int N = 5000;
int r, n, m, a[N], b[N];
long long dp[N][N];

int main() {

    enable_fast_io();

    cin >> r;

    n = m = 0;
    for(int i = 0;i < r;i++) {
        int x;
        cin >> x;
        if(x) a[n ++] = i;
        else b[m ++] = i;
    }

    if(n == 0) {
        cout << "0\n";
        return 0;
    }

    for(int i = 1;i < n;i++)
        dp[i][0] = INF;

    dp[0][0] = abs(a[0] - b[0]);
    for(int j = 1;j < m;j++)
        dp[0][j] = min(dp[0][j - 1], static_cast<long long>(abs(a[0] - b[j])));

    for(int i = 1;i < n;i++)
        for(int j = 1;j < m;j++)
            dp[i][j] = min(
                dp[i - 1][j - 1] + abs(a[i] - b[j]),
                dp[i][j - 1]
            );        

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}