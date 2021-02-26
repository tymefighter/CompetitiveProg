#include<iostream>
#include<vector>

using namespace std;

const int N = 50005, K = 105;
const long long MOD = 1000000007;

int n, k, c[N];
long long dp[N][K], dp1[N][K];
vector<vector<int> > a;

void readInput() {
    scanf("%d %d ", &n, &k);
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        scanf("%d ", &c[i]);
    
    for(int i = 0;i < n - 1;i++) {
        int u, v;
        scanf("%d %d ", &u, &v);
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void computeDP(int u, int parent) {
    for(int v : a[u]) {
        if(v == parent)
            continue;

        computeDP(v, u);
    }

    if(a[u].size() == 0 || (parent != -1 && a[u].size() == 1)) {
        if(c[u] == 0) {
            dp[u][0] = 1;
            dp[u][1] = 0;
        }
        else {
            dp[u][0] = 0;
            dp[u][1] = 1;
        }
        
        for(int j = 2;j <= k;j++)
            dp[u][j] = 0;

        return;
    }

    vector<int> children;
    for(int v : a[u]) {
        if(v == parent)
            continue;
        
        children.push_back(v);
    }

    for(int j = 0;j <= k;j++)
        dp1[0][j] = dp[children[0]][j] + (j == 0 ? 1 : 0);
    // special for j = 0, we can make 0 by not picking any node

    for(int i = 1;i < children.size();i++) {
        for(int j = 0;j <= k;j++) {
            dp1[i][j] = 0;

            for(int x = 0;x <= j;x++) {
                dp1[i][j] = (
                        dp1[i][j] + (   
                            (dp1[i - 1][j - x] * 
                            (dp[children[i]][x] + (x == 0 ? 1 : 0))) % MOD
                        )
                    ) % MOD;
            }
        }
    }

    if(c[u] == 0) {
        for(int j = 0;j <= k;j++)
            dp[u][j] = 
                dp1[static_cast<int>(children.size()) - 1][j];
    }
    else {
        dp[u][0] = 0;
        for(int j = 1;j <= k;j++)
            dp[u][j] = 
                dp1[static_cast<int>(children.size()) - 1][j - 1];

    }
}

void solve() {
    computeDP(0, -1);

    long long ans = 0;
    for(int i = 0;i < n;i++) {
        ans = (ans + dp[i][k]) % MOD;
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