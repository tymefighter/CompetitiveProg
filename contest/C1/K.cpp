#include<iostream>
#include<vector>

using namespace std;

int LCS(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n + 1, (vector<int>(m + 1)));

    dp[0][0] = 0;
    for(int i = 1;i <= n;i++)
        dp[i][0] = 0;
    for(int j = 1;j <= m;j++)
        dp[0][j] = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }

    return dp[n][m];
}

int main() {

    int cno = 1;
    string a, b;
    while(getline(cin, a)) {
        if(a[0] == '#')
            break;
        getline(cin, b);

        printf(
            "Case #%d: you can visit at most %d cities.\n",
            cno, 
            LCS(a, b)
        );

        cno ++;
    }

    return 0;
}