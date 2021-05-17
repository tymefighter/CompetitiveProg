#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 5000;
int n;
long long a[N], b[N];
long long pre_sum[N], suf_sum[N], range_sum[N][N];

void read() {
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
}

void compute_sum() {
    pre_sum[0] = a[0] * b[0];
    for(int i = 1;i < n;i++)
        pre_sum[i] = pre_sum[i - 1] + a[i] * b[i];

    suf_sum[n - 1] = a[n - 1] * b[n - 1];
    for(int i = n - 2;i >= 0;i--)
        suf_sum[i] = suf_sum[i + 1] + a[i] * b[i];

    range_sum[n - 1][n - 1] = a[n - 1] * b[n - 1];
    for(int i = 0;i < n - 1;i++) {
        
        range_sum[i][i] = a[i] * b[i];
        int p = i - 1, q = i + 1;
        while(p >= 0 && q < n) {
            range_sum[p][q] = range_sum[p + 1][q - 1]
                + a[p] * b[q] + a[q] * b[p];

            p --, q ++;
        }

        range_sum[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
        p = i - 1, q = i + 2;
        while(p >= 0 && q < n) {
            range_sum[p][q] = range_sum[p + 1][q - 1]
                + a[p] * b[q] + a[q] * b[p];

            p --, q ++;
        }
    }
}

void solve() {
    long long ans = pre_sum[n - 1];

    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            long long value = (i > 0 ? pre_sum[i - 1] : 0)
                + (j < n - 1 ? suf_sum[j + 1] : 0)
                + range_sum[i][j];

            ans = max(ans, value);
        }
    }

    cout << ans << "\n";
}

int main() {

    enable_fast_io();

    read();
    compute_sum();
    solve();

    return 0;
}