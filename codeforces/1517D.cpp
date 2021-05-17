#include <iostream>
#include <vector>

using namespace std;

struct Index {
    int i, j, r;

    Index(int i_, int j_, int r_):
        i(i_), j(j_), r(r_) {}
};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 500, K = 11;
int n, m, k;
int edge[N][N][4]; // 0 -> up, 1 -> down, 2 -> left, 3 -> right
int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

void read() {
    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m - 1;j++) {
            int wt;
            cin >> wt;
            edge[i][j][3] = edge[i][j + 1][2] = wt;
        }
    }

    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < m;j++) {
            int wt;
            cin >> wt;
            edge[i][j][1] = edge[i + 1][j][0] = wt; 
        }
    }
}

long long dp[K][N][N];

void compute_dp() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) 
            dp[0][i][j] = 0;
    }

    for(int r = 1;r <= k;r++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                dp[r][i][j] = -1;

                for(int p = 0;p < 4;p++) {
                    int prev_i = i - ar[p], prev_j = j - ac[p];

                    if(prev_i >= 0 && prev_i < n 
                        && prev_j >= 0 && prev_j < m
                        && (dp[r][i][j] == -1 
                            || dp[r - 1][prev_i][prev_j] 
                                + edge[prev_i][prev_j][p] < dp[r][i][j]))
                        dp[r][i][j] = dp[r - 1][prev_i][prev_j] 
                            + edge[prev_i][prev_j][p];
                }
            }
        }
    }
}

void solve() {
    if(k & 1) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++)
                cout << "-1 ";
            cout << "\n";
        }
        return;
    }

    k /= 2;
    compute_dp();
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cout << 2 * dp[k][i][j] << " ";
        cout << "\n";
    }
}

int main() {

    enable_fast_io();

    read();
    solve();

    return 0;
}