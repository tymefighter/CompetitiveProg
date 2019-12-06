#include<iostream>

using namespace std;

const int N = 200005;
int n, c;
int a[N], b[N], dp[N][2];

void read()
{
    cin>>n>>c;
    
    int i;
    for(i = 1;i <= n - 1;i++)
        cin>>a[i];
    for(i = 1;i <= n - 1;i++)
        cin>>b[i];
}

void solve()
{
    dp[1][1] = c;
    dp[1][0] = 0;
    cout<<"0 ";
    for(int i = 2;i <= n;i++)
    {
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
        dp[i][1] = min(dp[i - 1][0] + b[i - 1] + c, dp[i - 1][1] + b[i - 1]);
        cout<<min(dp[i][0], dp[i][1])<<" ";
    }
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}