#include <iostream>

using namespace std;

const int N = 100, M = 2000;
const int ADD = N * M, MAX_NUM = 2 * N * M + 1;
int n, a[N];
bool dp[N][MAX_NUM];

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    for(int i = 0;i < n;i++)
        for(int j = 0;j < MAX_NUM;j++)
            dp[i][j] = false;
    
    dp[0][ADD + a[0]] = dp[0][ADD - a[0]] = true;

    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < MAX_NUM;j++) {
            if(j + a[i + 1] < MAX_NUM) dp[i + 1][j + a[i + 1]] |= dp[i][j];
            if(j - a[i + 1] >= 0) dp[i + 1][j - a[i + 1]] |= dp[i][j];
        }
    }

    if(!dp[n - 1][ADD]) {
        cout << "0\n";
        return;
    }

    int min_pow = -1, min_pow_idx = -1;
    for(int i = 0;i < n;i++) {
        int pow = a[i] & -a[i];

        if(min_pow_idx == -1 || pow < min_pow) {
            min_pow = pow;
            min_pow_idx = i;
        }
    }

    cout << "1\n" << min_pow_idx + 1 << "\n";
}

int main() {

    enable_fast_io();

    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];

    solve();

    return 0;
}