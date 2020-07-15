#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 1005;
int n;
string s;
int dp[N][N];
// dp[l][i]: length of longest palindrome we can
// get from s[i .. i + l - 1]

void solve() {
    if(n == 0) {
        cout << "0\n";
        return;
    }
    
    for(int i = 0;i < n;i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(int l = 2;l <= n;l++) {
        for(int i = 0;i < n;i++) {
            if(i + l > n)
                dp[l][i] = 0;
            else {
                if(s[i] == s[i + l - 1])
                    dp[l][i] = dp[l - 2][i + 1] + 2;
                else
                    dp[l][i] = max(dp[l - 1][i], dp[l - 1][i + 1]);
            }
        }
    }

    cout << dp[n][0] << "\n";
}

int main() {

    int t;
    getline(cin, s);
    t = stoi(s);

    while(t --) {
        getline(cin, s);
        n = s.size();
        solve();
    }
    return 0;
}