#include<iostream>

using namespace std;

const int INF = static_cast<int>(1e8);
const int N = static_cast<int>(1e5 + 5);

int n, a[N];
int dp[N][2];

void readInput() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
}

void solve() {
    int ans = 0;
    for(int val = -30;val <= 30;val++) {
        dp[0][0] = (a[0] >= val ? -INF : a[0]);
        dp[0][1] = (a[0] == val ? 0 : -INF);

        for(int i = 1;i < n;i++) {
            if(a[i] == val)
                dp[i][1] = max(max(dp[i - 1][0], 0), dp[i - 1][1] + a[i]);
            else if(a[i] > val)
                dp[i][1] = -INF;
            else
                dp[i][1] = dp[i - 1][1] + a[i];

            if(a[i] >= val)
                dp[i][0] = -INF;
            else
                dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);

            ans = max(ans, dp[i][1]);
        }
    }

    cout << ans << "\n";
}

int main() {

    readInput();
    solve();

    return 0;
}