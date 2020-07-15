#include<iostream>

using namespace std;

const int N = 505;
const long long MAX_VAL = (1ll << 31ll) - 1;

string s;
int n;
long long dp[N];

int char2int(char c) {
    return c - '0';
}

void solve() {
    dp[0] = char2int(s[0]);

    for(int i = 1;i < n;i++) {
        dp[i] = dp[i - 1] + char2int(s[i]);

        int j = i - 1;
        long long pw = 1, val = 0;
        while(j >= -1 && val + char2int(s[j + 1]) * pw <= MAX_VAL) {
            val += char2int(s[j + 1]) * pw;

            if(s[j + 1] != '0')
                dp[i] = max(dp[i], (j == -1 ? 0 : dp[j]) + val);
            
            pw *= 10;
            j --;
        }
    }

    cout << dp[n - 1] << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> s;
        n = s.size();
        solve();
    }
    return 0;
}