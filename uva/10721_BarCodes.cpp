#include<iostream>

using namespace std;

long int dp[51][51];
int N, K, M;

long int solve()
{
    int n, k, x;
    dp[0][0] = 1;

    for(n = 1;n <= N;n++)
        dp[n][0] = 0;
    
    for(k = 1;k <= K;k++)
        dp[0][k] = 0;
    
    for(k = 1;k <= K;k++)
    {
        for(n = 1;n <= N;n++)
        {
            dp[n][k] = 0; // we zero this because we do not calculate the value of dp[n][k-1] for all n, so it might retain previous values
            for(x = 1;x <= min(n, M);x++)
                dp[n][k] += dp[n - x][k - 1];
        }
    }

    return dp[N][K];
}

int main()
{
    while(cin>>N>>K>>M)
        cout<<solve()<<"\n";

    return 0;
}