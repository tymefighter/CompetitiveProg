#include<iostream>
#define MOD 1000000007

using namespace std;

int n, k;
long long int dp[2002][2002];

void solve()
{
    int i, j, r;
    for(i = 0;i <= k;i++)
    {
        for(j = 0;j <= n;j++)
            dp[i][j] = 0;
    }

    for(j = 1;j <= n;j++)
        dp[1][j] = 1;

    for(i = 1;i <= k - 1;i++)
    {
        for(j = 1;j <= n;j++)
        {
            for(r = j;r <= n;r += j)
                dp[i + 1][r] = (dp[i + 1][r] + dp[i][j]) % MOD;
        }
    }

    long long int ans = 0;

    for(j = 1;j <= n;j++)
        ans = (ans + dp[k][j]) % MOD;
    cout<<ans<<"\n";
}

int main()
{
    cin>>n>>k;
    solve();
    return 0;
}