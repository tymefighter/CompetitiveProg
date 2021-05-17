#include <iostream>
#include <map>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100000, M = 19;
int n, q, a[N];
int next_index[N], dp[M][N];

void read() {
    cin >> n >> q;
    for(int i = 0;i < n;i++) cin >> a[i];
}

void compute() {
    // Compute next_index[...]
    map<int, int> prime_index;
    for(int i = 0;i < n;i++) {
        int x = a[i];

        next_index[i] = n;
        for(long long y = 2;y * y <= x;y++) {
            if(x % y != 0) continue;

            while(x % y == 0) x /= y;

            if(prime_index[y] <= i) {
                int j = i + 1;
                while(j < n && a[j] % y != 0) j++;

                prime_index[y] = j;
            }

            next_index[i] = min(next_index[i], prime_index[y]);
        }

        if(x > 1) {
            if(prime_index[x] <= i) {
                int j = i + 1;
                while(j < n && a[j] % x != 0) j++;

                prime_index[x] = j;
            }

            next_index[i] = min(next_index[i], prime_index[x]);
        }
    }

    for(int i = n - 2;i >= 0;i--)
        next_index[i] = min(next_index[i], next_index[i + 1]);
    
    // Compute dp[..][..]
    for(int i = 0;i < n;i++)
        dp[0][i] = next_index[i];

    for(int i = 0;i < n;i++)
        cout << i << " " << next_index[i] << "||||\n";
    
    for(int j = 1;j < M;j++)
        for(int i = 0;i < n;i++)
            dp[j][i] = dp[j - 1][i] == n ? n : dp[j - 1][dp[j - 1][i]];
}

void solve() {
    while(q --) {
        int l, r;
        cin >> l >> r;
        l --, r --;

        int ans = 0;
        for(int i = M - 1;i >= 0;i--) {
            if(dp[i][l] <= r) {
                ans += (1 << i);
                l = dp[i][l];
            }
        }

        ans ++;
        cout << ans << "\n";
    }
}

int main() {

    enable_fast_io();

    read();
    compute();
    solve();

    return 0;
}