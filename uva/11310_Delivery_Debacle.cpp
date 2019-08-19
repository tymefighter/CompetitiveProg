#include<iostream>

using namespace std;

int n;
long long int dp[41];

void solve()
{
    dp[0] = dp[1] = 1;
    dp[2] = 5;

    for(int i = 3;i <= n;i++)
        dp[i] = dp[i - 1] + 4 * dp[i - 2] + 2 * dp[i - 3];

    cout<<dp[n]<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve();
    }
    return 0;
}