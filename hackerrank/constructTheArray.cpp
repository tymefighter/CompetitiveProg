#include<iostream>
#define MOD 1000000007

using namespace std;

long long int dp[100005][2];
long long int n, k, x;

void solve()
{
     if(x == 1)
     {
         dp[0][0] = 0;
         dp[0][1] = 1;
     }
     else
     {
         dp[0][0] = 1;
         dp[0][1] = 0;
     }
     
     
     for(int i = 1;i <= n - 2;i++)
     {
         dp[i][0] = ((k - 2) * dp[i - 1][0] + (k - 1) * dp[i - 1][1]) % MOD;
         dp[i][1] = dp[i - 1][0];
     }
     
     
    cout<<dp[n - 2][0]<<"\n";
}


int main()
{
    cin>>n>>k>>x;
    solve();
    return 0;
}