#include <iostream>

using namespace std;

const int N = 1000;
const int INF = 100000000;
int n, x, y;
string s;
int dp[N][2];

int char2int(char c) {
    if(c == 'C') return 0;
    else return 1;
}

int value(int p, int q) {
    if(p == 1 && q == 0) return y;
    else if(p == 0 && q == 1) return x;
    else return 0;
}

int solve() {
    dp[0][0] = dp[0][1] = 0;
    if(s[0] == 'C') dp[0][1] = INF;
    else if(s[0] == 'J') dp[0][0] = INF;

    for(int i = 1;i < n;i++) {
        if(s[i] == '?' && s[i - 1] == '?') {
            dp[i][0] = min(dp[i - 1][0] + value(0, 0), dp[i - 1][1] + value(1, 0));
            dp[i][1] = min(dp[i - 1][0] + value(0, 1), dp[i - 1][1] + value(1, 1));
        }
        else if(s[i - 1] == '?') {
            int p = char2int(s[i]);
            dp[i][p] = min(dp[i - 1][0] + value(0, p), dp[i - 1][1] + value(1, p));
            dp[i][1 - p] = INF;
        }
        else if(s[i] == '?') {
            int q = char2int(s[i - 1]);
            dp[i][0] = dp[i - 1][q] + min(value(q, 0), value(q, 0));
            dp[i][1] = dp[i - 1][q] + min(value(q, 1), value(q, 1));
        }
        else {
            int p = char2int(s[i]);
            int q = char2int(s[i - 1]);

            dp[i][p] = dp[i - 1][q] + value(q, p);
            dp[i][1 - p] = INF;
        }
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {

    int t;
    cin >> t;

    for(int i = 1;i <= t;i++) {
        cin >> x >> y >> s;
        n = s.size();
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}