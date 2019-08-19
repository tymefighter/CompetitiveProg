#include<iostream>

using namespace std;

double dp[505][505], p;
int n;

double pw(int i)
{
    if(i == 0)
        return 1.;
    else if(i % 2)
        return pw(i - 1) * p;
    else
    {
        double val = pw(i / 2);
        return val * val;
    }
}

void solve()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = i;j <= n;j++)
            dp[i][j] = 1.;
        if(i > 0)
            dp[i][i - 1] = 1. - pw(i);
    }

    for(i = 2;i <= n;i++)
    {
        for(j = 0;j <= i - 2;j++)
            dp[i][j] = dp[i - 1][j] - dp[i - j - 2][j] * (1. - p) * pw(j + 1);
    }

    double ans = 0;

    for(j = 1;j <= n;j++)
        ans += (dp[n][j] - dp[n][j - 1]) * j;
    printf("%0.10lf\n", ans);
}

int main()
{
    while(cin>>n>>p)
    {
        if(!n)
            break;
        solve();
    }
    return 0;
}

