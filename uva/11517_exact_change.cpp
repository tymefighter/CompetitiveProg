#include<iostream>

using namespace std;

int dp[102][10002], dp2[102][10002], a[102];
int s, n;
int val;

void read()
{
    cin>>s>>n;

    for(int i = 1;i <= n;i++)
        cin>>a[i];
}

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= s;j++)
        {
            dp2[i][j] = dp[i][j] = -1;
        }
    }
}

int solve(int i, int x)
{
    if(x <= 0)
        return -x;

    if(dp[i][x] != -1)
        return dp[i][x];
    
    if(i == 0)
    {
        dp[i][x] = 100000000;
        return 100000000;
    }

    dp[i][x] = min(solve(i - 1, x), solve(i - 1, x - a[i]));
    return dp[i][x];
}

int solve2(int i, int x)
{

    if(x <= 0)
    {
        if(-x == val)
            return 0;
        else
            return 100000000;
    }

    if(dp2[i][x] != -1)
        return dp2[i][x];
    
    if(i == 0)
    {
        dp2[i][x] = 100000000;
        return 100000000;
    }

     dp2[i][x] = min(solve2(i - 1, x), solve2(i - 1, x - a[i]) + 1);
     return dp2[i][x];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        reset();
        val = solve(n, s);
        cout<<val + s<<' '<<solve2(n, s)<<"\n";
    }
    return 0;
}