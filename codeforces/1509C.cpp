#include <iostream>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 2005;
int n;
long long a[N], dp[N][N], max_val[N][N], min_val[N][N];

void read_input() {
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a + n);
}

void compute_quant() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            dp[i][j] = -1;

            if(j < i) max_val[i][j] = min_val[i][j] = -1;
            else if(j == i) max_val[i][j] = min_val[i][j] = a[i];
            else {
                max_val[i][j] = max(max_val[i][j - 1], a[j]);
                min_val[i][j] = min(min_val[i][j - 1], a[j]);
            }
        }
    }
}

long long compute_dp(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];

    if(l == r)
        dp[l][r] = 0;
    else
        dp[l][r] = min(
            compute_dp(l + 1, r),
            compute_dp(l, r - 1)
        ) + max_val[l][r] - min_val[l][r];

    return dp[l][r];
}

int main() {

    enable_fast_io();

    read_input();
    compute_quant();
    cout << compute_dp(0, n - 1) << "\n";

    return 0;
}