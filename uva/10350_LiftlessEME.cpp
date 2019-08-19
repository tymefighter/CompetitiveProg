#include<iostream>
#include<string>
#define MAX 100000000

using namespace std;

int n, m;
int dp[125][17], tm[125][17][17];
string s;

void reset()
{
    int i, j, k;
    for(i = 0; i <= n;i++)
    {
        for(j = 0;j < m;j++)
        {
            dp[i][j] = -1;
        }
    }
}

void read()
{
    cin>>n>>m;
    reset();

    int i, j, k;
    for(i = 1;i <= n - 1;i++)
    {
        for(j = 0;j < m;j++)
        {
            for(k = 0;k < m;k++)
                cin>>tm[i][j][k];
        }
    }
}

int solve(int i, int r)
{
    if(i == 1)
        return 0;

    if(dp[i][r] != -1)
        return dp[i][r];

    int min_val = MAX;
    for(int x = 0;x < m;x++)
        min_val = min(min_val, solve(i - 1, x) + tm[i - 1][x][r]);

    dp[i][r] = min_val;
    return min_val;
}

int main()
{
    int ans;
    while(cin>>s)
    {
        read();
        ans = MAX;

        for(int r = 0;r < m;r++)
            ans = min(ans, solve(n, r));
        cout<<s<<"\n";
        cout<<ans + (n - 1) * 2<<"\n";
    }
    return 0;
}