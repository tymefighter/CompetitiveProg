#include<iostream>
#include<algorithm>

using namespace std;

const int N = 200005;
int n, e[N], dp[N];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> e[i];

    sort(e, e + n);
}

void solve() {
    dp[0] = (e[0] == 1 ? 1 : 0);

    for(int i = 1;i < n;i++) {
        dp[i] = dp[i - 1];

        if(i - (e[i] - 1) >= 0)
            dp[i] = max(dp[i], (i >= e[i] ? dp[i - e[i]] : 0) + 1);
    }

    cout << dp[n - 1] << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        readInput();
        solve();
    }
    return 0;
}