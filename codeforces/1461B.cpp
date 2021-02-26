#include <iostream>

using namespace std;

const int N = 505;
int n, m;
char a[N][N];
long long dp[N][N], leftIdx[N][N];

void readInput() {
    scanf("%d %d ", &n, &m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%c ", &a[i][j]);

            if(a[i][j] == '*') {
                if(j > 0 && a[i][j - 1] == '*') leftIdx[i][j] = leftIdx[i][j - 1];
                else leftIdx[i][j] = j - 1;
            }
            else leftIdx[i][j] = -1;
        }
    }
}

void solve() {
    long long ans = 0;

    for(int j = 0;j < m;j++) {
        if(a[0][j] == '*') dp[0][j] = 1;
        else dp[0][j] = 0;

        ans += dp[0][j];
    }

    for(int i = 1;i < n;i++) {
        dp[i][0] = (a[i][0] == '*' ? 1 : 0);
        ans += dp[i][0];

        for(int j = 1;j < m;j++) {
            if(a[i][j] == '*' && a[i - 1][j - 1] == '*') {
                dp[i][j] = min(dp[i - 1][j - 1] + 2, j - leftIdx[i][j]);

                if((dp[i][j] & 1) == 0)
                    dp[i][j] --;
            }
            else if(a[i][j] == '*')
                dp[i][j] = 1;
            else
                dp[i][j] = 0;


            
            long long ht = (dp[i][j] > 0 ? dp[i][j] / 2 + 1 : 0);
            ans += ht;
        }
    }

    printf("%lld\n", ans);
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
