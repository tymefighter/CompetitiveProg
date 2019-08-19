#include<iostream>

using namespace std;

int n;
int a[10][1001];
int dp[10][1001];

void read()
{
    cin>>n;
    n /= 100;

    int i, d;
    for(i = 9;i >= 0;i--)
    {
        for(d = 0;d < n;d++)
        {
            cin>>a[i][d];
            a[i][d] = -a[i][d];
        }
    }
}

int min3(int a, int b, int c)
{
    return min(a, min(b, c));
}

int solve()
{
    int i, d;
    int val1, val2, val3;
    dp[0][0] = 0;
    
    for(i = 1;i <= 9;i++)
        dp[i][0] = 100000000;
    
    for(d = 1;d <= n;d++)
    {
        for(i = 0;i <= 9;i++)
        {
            if(i > 0 && i < 9)
                dp[i][d] = min3(dp[i-1][d-1] + a[i-1][d-1] + 60, dp[i][d-1] + a[i][d-1] + 30, dp[i+1][d-1] + a[i+1][d-1] + 20);
            else if(i == 0)
                dp[i][d] = min(dp[i][d-1] + a[i][d-1] + 30, dp[i+1][d-1] + a[i+1][d-1] + 20);
            else if(i == 9)
                dp[i][d] = min(dp[i-1][d-1] + a[i-1][d-1] + 60, dp[i][d-1] + a[i][d-1] + 30);
        }
    }

    return dp[0][n];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<"\n\n";
    }
    return 0;
}