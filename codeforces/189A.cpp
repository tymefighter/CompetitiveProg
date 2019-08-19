#include<iostream>
#include<cstring>

using namespace std;

int dp[4100];
int a[3];
int n;

void read()
{
    cin>>n;
    cin>>a[0]>>a[1]>>a[2];
}

void reset()
{
    int i;
    for(i = 0;i <= n;i++)
        dp[i] = -1;
}

int solve(int x)
{
    if(dp[x] != -1)
        return dp[x];

    if(x == 0)
    {
        dp[x] = 0;
        return 0;
    }
    
    int max_val = -10;
    for(int i = 0;i < 3;i++)
    {
        if(x - a[i] >= 0)
            max_val = max(max_val, solve(x - a[i]));
    }

    if(max_val == -1)
        dp[x] = -10;
    else
        dp[x] = max_val + 1;
    return dp[x];
}

int main()
{
    read();
    reset();
    cout<<solve(n)<<"\n";
    return 0;
}