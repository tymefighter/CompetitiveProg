#include<iostream>

using namespace std;

const int N = static_cast<int>(2e5 + 5);
int n, a[N];
long long dp[N];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

void solve() {
    if(n == 1) {
        printf("%d\n", a[0]);
        return;
    }

    dp[0] = 0;
    dp[1] = max(a[1] - a[0], 0);
    long long maxVal = max(dp[0], dp[1]);

    for(int i = 2;i < n;i++) {
        if(i % 2 == 0)
            dp[i] = max(dp[i - 2] + a[i - 1] - a[i], 0ll);
        else
            dp[i] = max(dp[i - 2] + a[i] - a[i - 1], 0ll);

        maxVal = max(maxVal, dp[i]);
    }

    for(int i = 0;i < n;i += 2)
        maxVal += a[i];

    printf("%lld\n", maxVal);
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