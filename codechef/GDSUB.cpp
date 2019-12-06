#include<iostream>
#include<vector>
#include<map>

using namespace std;

const long long int MOD = 1000000007;
int n, k;
long long int dp[8003][8003];
map<int, int> m;
vector<int> a;

void read()
{
    cin>>n>>k;
    int x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(m.find(x) == m.end())
            m[x] = 0;
        m[x] ++;
    }

    a.push_back(-1);
    for(auto p : m)
        a.push_back(p.second);

    n = a.size() - 1;           // update n and k
    k = min(n, k);
}

void solve()
{
    int i, j;

    dp[0][1] = 0;
    for(i = 1;i <= n;i++)
        dp[i][1] = (dp[i - 1][1] + a[i]) % MOD;

    for(i = 2;i <= n;i++)
    {
        for(j = 2;j <= k;j++)
            dp[i][j] = (dp[i - 1][j - 1] * a[i] + dp[i - 1][j]) % MOD;
    }

    int ans = 1;                // Empty subsequence (don't forget !)

    for(j = 1;j <= k;j++)
        ans = (ans + dp[n][j]) % MOD;
    cout<<ans<<"\n";
}

int main()
{

    read();
    solve();

    return 0;
}