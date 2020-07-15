#include<iostream>

using namespace std;

const int N = 10005;
const int INF = 100000000;
int n, a[N], dp[N][4];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

int solve() {
    for(int j = 0;j < 4;j++)
        dp[0][j] = 0;

    for(int i = 1;i < n;i++) {
        for(int j = 0;j < 4;j++) {
            dp[i][j] = INF;
            for(int k = 0;k < 4;k++) {
                if(a[i] > a[i - 1]) {
                    if(j > k)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                }
                else if(a[i] < a[i - 1]) {
                    if(j < k)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                }
                else {
                    if(j == k)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                }
            }
        }
    }

    int ans = dp[n - 1][0];
    for(int j = 1;j < 4;j++)
        ans = min(ans, dp[n - 1][j]);

    return ans;
}

int main() {
    int t;
    scanf("%d ", &t);
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}