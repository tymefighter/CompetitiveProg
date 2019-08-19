#include<iostream>
#define MOD 1000000007

using namespace std;

int n;
long long int dp[2][4];

void solve()
{
    dp[0][0] = 1;
    int i, j, k;
    for(i = 1;i <= n;i++)
    {
        for(j = 0;j < 4;j++)
        {
            dp[i % 2][j] = 0;
            for(k = 0;k < 4;k++)
            {
                if(k == j)
                    continue;
                dp[i % 2][j] = (dp[i % 2][j] + dp[1 - (i % 2)][k]) % MOD;
            }
        }
    }

    cout<<dp[n % 2][0]<<"\n";
}

int main()
{
    cin>>n;
    solve();
    return 0;
}