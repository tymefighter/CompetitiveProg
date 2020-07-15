#include<iostream>

using namespace std;

const int N = static_cast<int>(2e6 + 5);
const long long MOD = 1000000007; 
long long dp[N];

void computeDP() {
    dp[0] = dp[1] = dp[2] = 0;
    dp[3] = 4;
    for(int n = 4;n < N;n++) {
        dp[n] = max (
            2 * dp[n - 2] + dp[n - 1],
            4 
            + (4 * dp[n - 4]) % MOD
            + (4 * dp[n - 3]) % MOD
            + dp[n - 2]
        );
        dp[n] %= MOD;
    }
}

int main() {
    computeDP();

    int t;
    scanf("%d ", &t);
    while(t --) {
        int n;
        scanf("%d ", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}