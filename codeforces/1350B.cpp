#include<iostream>

using namespace std;

const int N = static_cast<int>(1e5) + 5;
int n, s[N + 1];
int dp[N + 1];

void readInput() {
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &s[i]);
}

void solve() {
    int ans = 1;
    dp[1] = 1;

    for(int i = 2;i <= n;i++) {
        dp[i] = 1;
        for(long long j = 1;j * j <= i;j++) {
            if(i % j == 0) {
                if(s[j] < s[i])
                    dp[i] = max(dp[i], dp[j] + 1);

                int j_d = i / j;
                if(j_d < i && s[j_d] < s[i])
                    dp[i] = max(dp[i], dp[j_d] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        readInput();
        solve();
    }
    return 0;
}