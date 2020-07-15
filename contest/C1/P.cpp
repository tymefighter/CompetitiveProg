#include<iostream>

using namespace std;

const int N = 1005, INF = static_cast<int>(1e8);

string s;
int n, m, k;
bool block[N][26];
int numDistChar[N], dp[N][26];
// dp[i][c]: min value if ith block has rightmost char of value c

int char2int(char c) {return c - 'a';}

void solve() {
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < 26;j++)
            block[i][j] = false;
    }

    for(int i = 0;i < m;i++) {
        for(int j = 0;j < k;j++)
            block[i][char2int(s[i * k + j])] = true;

        numDistChar[i] = 0;
        for(int j = 0;j < 26;j++)
            numDistChar[i] += (block[i][j] ? 1 : 0);
    }

    for(int j = 0;j < 26;j++) {
        if(!block[0][j])
            dp[0][j] = INF;
        else
            dp[0][j] = numDistChar[0];
    }

    for(int i = 1;i < m;i++) {
        for(int j = 0;j < 26;j ++) {
            dp[i][j] = INF;
            if(!block[i][j]) 
                continue;

            for(int jPrev = 0;jPrev < 26;jPrev ++) {
                if((jPrev != j && block[i][jPrev] == true)
                    || (jPrev == j && numDistChar[i] == 1))
                    dp[i][j] = min(dp[i][j], dp[i - 1][jPrev] + numDistChar[i] - 1);
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][jPrev] + numDistChar[i]);
            }
        }
    }

    int ans = INF;
    for(int j = 0;j < 26;j++)
        ans = min(ans, dp[m - 1][j]);

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> k >> s;
        n = s.size();
        m = n / k;
        solve();
    }

    return 0;
}