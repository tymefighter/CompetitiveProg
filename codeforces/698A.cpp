#include<iostream>

using namespace std;

int n;
int dp[105][3];
int a[105];

void reset()
{
    int i, j;
    for(i = 0;i <= n + 1;i++)
    {
        for(j = 0;j < 3;j++)
            dp[i][j] = -1;
    }
}

void read()
{
    cin>>n;
    reset();

    for(int i = 1;i <= n;i++)
        cin>>a[i];
}

int solve(int i, int p)
{
    if(i == 1)
        return 0;

    if(dp[i][p] != -1)
        return dp[i][p];
    
    int ans = solve(i - 1, 0) + 1;
    if(p == 0)
    {
        if(a[i - 1] & 1)
            ans = min(ans, solve(i - 1, 1));
        if(a[i - 1] & 2)
            ans = min(ans, solve(i - 1, 2));
    }
    else if(p == 1)
    {
        if(a[i - 1] & 2)
            ans = min(ans, solve(i - 1, 2));
    }
    else if(p == 2)
    {
        if(a[i - 1] & 1)
            ans = min(ans, solve(i - 1, 1));
    }

    dp[i][p] = ans;
    return ans;
}

int main()
{
    read();
    cout<<solve(n + 1, 0)<<"\n";
    return 0;
}