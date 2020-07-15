#include<iostream>

using namespace std;

const int K = 65, N = 8005;
const long long MOD = 1000000007;

int n, k, l[K], d[K];
long long dp[K][N];

void readInput() {
    scanf("%d %d ", &n, &k);

    for(int i = 0;i < k;i++)
        scanf("%d ", &l[i]);

    for(int i = 0;i < k;i++)
        scanf("%d ", &d[i]);
}

void solve() {
    for(int i = 0;i < k;i++) {
        dp[i][0] = 1;
        for(int j = 1;j <= n;j++) {
            dp[i][j] = 0;
            for(int r = 0;r <= d[i];r++) {
                if(i > 0) {
                    if(j >= r * l[i])
                        dp[i][j] += dp[i - 1][j - r * l[i]];
                }
                else
                    dp[i][j] += (j - r * l[i] == 0 ? 1 : 0);
                
                dp[i][j] %= MOD;
            }
        }
    }

    printf("%lld\n", dp[k - 1][n]);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}