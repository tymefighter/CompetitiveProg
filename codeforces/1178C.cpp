#include<iostream>
#define MOD 998244353
  

using namespace std;

int n, m;
long long dp[4][1002][1002];

void reset()
{
    int k, i, j;
    for(k = 0;k < 4;k++)
    {
        for(i = 0;i <= n;i++)
        {
            for(j = 0;j <= m;j++)
                dp[k][i][j] = -1;
        }
    }
}

long long int ct(int idx, int i, int j)
{
    if(i == 1 && j == 1)
        return 1;
    
    if(dp[idx][i][j] != -1)
        return dp[idx][i][j];

    long long int val1 = -1, val2 = -1;
    if(idx == 0)
    {

        if(i > 1)
            val1 = (ct(3, i - 1, j) + ct(0, i - 1, j));
        if(j > 1)
            val2 = ct(1, i, j - 1) + ct(0, i, j - 1);

        if(val1 == -1)
            dp[idx][i][j] = val2;
        else if(val2 == -1)
            dp[idx][i][j] = val1;
        else
            dp[idx][i][j] = min(val1, val2);
    }
    else if(idx == 1)
    {
        if(i > 1)
            val1 = ct(2, i - 1, j) + ct(1, i - 1, j);
        if(j > 1)
            val2 = ct(0, i, j - 1) + ct(1, i, j - 1);
        
        if(val1 == -1)
            dp[idx][i][j] = val2;
        else if(val2 == -1)
            dp[idx][i][j] = val1;
        else
            dp[idx][i][j] = min(val1, val2);
    }
    else if(idx == 2)
    {
        if(i > 1)
            val1 = ct(1, i - 1, j) + ct(2, i - 1, j);
        if(j > 1)
            val2 = ct(3, i, j - 1) + ct(2, i, j - 1);

        if(val1 == -1)
            dp[idx][i][j] = val2;
        else if(val2 == -1)
            dp[idx][i][j] = val1;
        else
            dp[idx][i][j] = min(val1, val2);
    }
    else if(idx == 3)
    {
        if(i > 1)
            val1 = ct(0, i - 1, j) + ct(3, i - 1, j);
        if(j > 1)
            val2 = ct(2, i, j - 1) + ct(3, i, j - 1);

        if(val1 == -1)
            dp[idx][i][j] = val2;
        else if(val2 == -1)
            dp[idx][i][j] = val1;
        else
            dp[idx][i][j] = min(val1, val2);
    }

    dp[idx][i][j] %= MOD;
    return dp[idx][i][j];
}

int main()
{
    cin>>m>>n;
    reset();
    long long int ans = 0;

    for(int i = 0;i < 4;i++)
        ans = (ans + ct(i, n, m)) % MOD;

    cout<<ans<<"\n";
    return 0;
}