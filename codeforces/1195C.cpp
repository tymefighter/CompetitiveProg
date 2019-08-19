#include<iostream>

using namespace std;

int n;
long long int dp[100005][2];
long long int a[100005][2];

void read()
{
    cin>>n;
    int i, j;
    for(i = 0;i < 2;i++)
    {
        for(j = 1;j <= n;j++)
            cin>>a[j][i];
    }
}

void solve()
{
    dp[0][0] = dp[0][1] = 0ll;

    int i, j;
    for(i = 1; i <= n;i++)
    {
        for(j = 0;j < 2;j++)
            dp[i][j] = max(dp[i - 1][1 - j] + a[i][1 - j], dp[i - 1][j]);
    }

    cout<<max(dp[n][0], dp[n][1])<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}