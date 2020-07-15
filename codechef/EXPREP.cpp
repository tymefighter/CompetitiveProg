#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

const int N = 105, NUMCHAR = 26;
long long MOD = 998244353;

char s[N];
long long n, wt[NUMCHAR];
long long w[N][N], dp[N][N];

void readInput() {
    scanf("%s ", s);
    n = strlen(s);
    for(int i = 0;i < NUMCHAR;i++)
        scanf("%lld ", &wt[i]);
}

inline int char2int(char c) {return c - 'a';}

void computeWt() {
    for(int i = 0;i < n;i++) {
        w[i][i] = wt[char2int(s[i])] % MOD;
        for(int j = i + 1;j < n;j++)
            w[i][j] = (w[i][j - 1] + wt[char2int(s[j])]) % MOD;
    }
}

long long binaryExp(long long x, long long m, long long mod) {
    if(m == 0)
        return 1;
    else if(m % 2 == 1)
        return (binaryExp(x, m - 1, mod) * x) % mod;
    else {
        long long val = binaryExp(x, m / 2, mod);
        return (val * val) % mod;
    }
}

void solve() {
    computeWt();

    long long ans = 0;
    for(int i = 0;i < n;i++) {
        dp[i][i] = w[i][i];
        ans = (ans + dp[i][i]) % MOD;
        
        set<int> prefixLengths;
        prefixLengths.insert(1);

        for(int j = i + 1;j < n;j++) {
            dp[i][j] = 0;
            int prevLen = j - i;

            vector<int> removeLen;
            for(int len : prefixLengths) {
                if(s[j] == s[i + (prevLen % len)])
                    dp[i][j] = (dp[i][j] + w[i][i + len - 1]) % MOD;
                else
                    removeLen.push_back(len);
            }

            for(int len : removeLen)
                prefixLengths.erase(len);

            dp[i][j] = (dp[i][j] + w[i][j]) % MOD;
            prefixLengths.insert(j - i + 1);

            ans = (ans + dp[i][j]) % MOD;
        }
    }

    ans = (ans * binaryExp((n * (n + 1)) / 2, MOD - 2, MOD)) % MOD;
    if(ans < 0)
        ans += MOD;
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