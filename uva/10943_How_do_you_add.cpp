#include<iostream>
#define MOD_VAL 1000000

using namespace std;

int dp[101][101];

int N, K;

int solve()
{
    int n, k, x;
    
    for(n = 0;n <= N;n++)
        dp[n][1] = 1;

    long long int val = 0;
    for(n = 0;n <= N;n++)
    {
        for(k = 2;k <= K;k++)
        {
            val = 0;
            for(x = 0;x <= n;x++)
            {
                val = (val % MOD_VAL + dp[x][k-1] % MOD_VAL) % MOD_VAL;
            }
            dp[n][k] = val;
        }
    }

    return dp[N][K];
}

int main()
{
    while(cin>>N>>K)
    {
        if((N | K) == 0)
            break;
        cout<<solve()<<"\n";
    }

    return 0;
}