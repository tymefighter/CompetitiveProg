#include <iostream>

using namespace std;

const int N = 401;
int n;
long long mod, pw[N], binom[N][N], dp[N][N];

void compute_dp() {

    // pow
    pw[0] = 1;
    for(int i = 1;i <= n;i++) pw[i] = (pw[i - 1] * 2) % mod;

    // binom
    binom[1][0] = binom[1][1] = 1;
    for(int i = 2;i <= n;i++) binom[1][i] = 0;

    for(int m = 2;m <= n;m++) {
        binom[m][0] = 1;

        for(int i = 1;i <= n;i++) {
            if(i > m) binom[m][i] = 0;
            else binom[m][i] = (binom[m - 1][i - 1] + binom[m - 1][i]) % mod;
        }
    }

    // dp
    for(int k = 0;k <= n;k++) {
        dp[0][k] = 0;
        dp[1][k] = (k == 1 ? 1 : 0);
    }
    
    for(int i = 2;i <= n;i++) {
        dp[i][0] = 0;

        for(int k = 1;k <= n;k++) {
            dp[i][k] = (k == i ? pw[i - 1] : 0);

            for(int x = 1;x <= min(i - 1, k);x++) {
                long long value = (dp[i - x - 1][k - x] * pw[x - 1]) % mod;
                value = (value * binom[k][x]) % mod;

                dp[i][k] = (dp[i][k] + value) % mod;
            }
        }
    }
}

int main() {

    cin >> n >> mod;

    compute_dp();
    
    long long ans = 0;
    for(int k = 0;k <= n;k++) ans = (ans + dp[n][k]) % mod;
    cout << ans << "\n";

    return 0;
}