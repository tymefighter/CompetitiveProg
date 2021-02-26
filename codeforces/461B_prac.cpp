#include<iostream>
#include<vector>

using namespace std;

const int N = 100005;
const long long MOD = 1000000007;

long long dp[N][2];
int n, color[N];
vector<vector<int> > a;

void readInput() {
    scanf("%d ", &n);

    a.clear();
    a.resize(n);

    for(int i = 0;i < n - 1;i++) {
        int parent;
        scanf("%d ", &parent);
        a[parent].push_back(i + 1);
        a[i + 1].push_back(parent);
    }

    for(int i = 0;i < n;i++) {
        scanf("%d ", &color[i]);
        dp[i][0] = dp[i][1] = -1;
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

long long computeDP(int u, int c, int parent) {

    if(dp[u][c] != -1)
        return dp[u][c];

    if(parent != -1 && a[u].size() <= 1) {
        dp[u][c] = (c == color[u] ? 1 : 0);
        return dp[u][c];
    }

    if(c == 0 && color[u] == 1)
        dp[u][c] = 0;
    else if(c == color[u]) {
        long long prod = 1;
        for(int v : a[u]) {
            if(v == parent)
                continue;

            prod = 
                (prod * ((computeDP(v, 0, u) + computeDP(v, 1, u)) % MOD))
                % MOD;
        }

        dp[u][c] = prod;
    }
    else {
        long long prod = 1;
        for(int v : a[u]) {
            if(v == parent)
                continue;

            prod = 
                (prod * ((computeDP(v, 0, u) + computeDP(v, 1, u)) % MOD))
                % MOD;
        }

        long long ans = 0;
        for(int v : a[u]) {
            if(v == parent)
                continue;

            long long val = (prod * computeDP(v, 1, u)) % MOD;
            val = (val * binaryExp(
                    computeDP(v, 0, u) + computeDP(v, 1, u),
                    MOD - 2,
                    MOD)) % MOD;
            ans = (ans + val) % MOD;
        }

        dp[u][c] = ans;
    }

    return dp[u][c];
}

int main() {

    readInput();
    printf("%lld\n", computeDP(0, 1, -1));

    return 0;
}