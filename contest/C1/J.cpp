#include<iostream>

using namespace std;

const int N = 85, INF = static_cast<int>(1e8);
string a, b;
int n, m, dp[N][N];
char op[N][N];

void solve() {
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
        dp[i][0] = i;
    for(int j = 1;j <= m;j++)
        dp[0][j] = j;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = INF;

            if(dp[i - 1][j] + 1 < dp[i][j]) {
                dp[i][j] = dp[i - 1][j] + 1;
                op[i][j] = 'd';
            }

            if(dp[i][j - 1] + 1 < dp[i][j]) {
                dp[i][j] = dp[i][j - 1] + 1;
                op[i][j] = 'i';
            }

            if(dp[i - 1][j - 1] + 1 < dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                op[i][j] = 's';
            }

            if(a[i - 1] == b[j - 1] && dp[i - 1][j - 1] < dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1];
                op[i][j] = 'n';
            }
        }
    }

    cout << dp[n][m] << "\n";
    int i = n, j = m, ct = 1;

    while(i > 0 && j > 0) {
        switch(op[i][j]) {
            case 'd':
                cout << ct ++;
                cout << " Delete " << i << "\n";
                i --;
                break;
            case 'i':
                cout << ct ++;
                cout << " Insert " << i + 1 << "," << b[j - 1] << "\n";
                j --;
                break;
            case 's':
                cout << ct ++;
                cout << " Replace " << i << "," << b[j - 1] << "\n";
            case 'n':
                i --;
                j --;
                break;
        }
    }

    while(i > 0) {
        cout << ct ++;
        cout << " Delete " << i << "\n";
        i --;
    }
    while(j > 0) {
        cout << ct ++;
        cout << " Insert " << i + 1 << "," << b[j - 1] << "\n";
        j --;
    }
}

int main() {

    int ct = 0;
    while(getline(cin, a)) {
        if(ct)
            cout << "\n";
        getline(cin, b);
        n = a.size();
        m = b.size();
        solve();
        ct ++;
    }
    return 0;
}