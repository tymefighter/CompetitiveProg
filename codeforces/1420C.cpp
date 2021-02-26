#include<iostream>

using namespace std;

const long long INF = 1000000000000000;
const int N = 300005;
int n, a[N];
long long dp[N][2];

void readInput() {
    int q;
    scanf("%d %d ", &n, &q);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

void solve() {
    dp[0][0] = a[0];
    dp[0][1] = -INF;

    for(int i = 1;i < n;i++) {
        dp[i][0] = max(
            static_cast<long long>(a[i]), 
            max(dp[i - 1][0], dp[i - 1][1] + a[i])
        );
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i]);
    }

    printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
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