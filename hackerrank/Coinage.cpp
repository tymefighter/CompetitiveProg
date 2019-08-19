#include<iostream>

using namespace std;

int n, a, b, c, d;
int val[4] = {1, 2, 5, 10}, amt[4];
int dp[1001][4][1001];

void reset()
{
    amt[0] = min(n, a);
    amt[1] = min(n / 2, b);
    amt[2] = min(n / 5, c);
    amt[3] = min(n / 10, d);

    int i, j, k;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j < 4;j++)
        {
            for(k = 0;k <= max(max(amt[0], amt[1]), max(amt[2], amt[3])); k++)
                dp[i][j][k] = -1;
        }
    }
}

int count(int m, int i, int x)
{
    if(m < 0 || x < 0)
        return 0;
    if(m == 0)
        return 1;

    if(dp[m][i][x] != -1)
        return dp[m][i][x];
    
    if(i == 0)
    {
        if(x >= m)
            dp[m][i][x] = 1;
        else
            dp[m][i][x] = 0;
        
        return dp[m][i][x];
    }

    dp[m][i][x] = count(m - val[i], i, x - 1) + count(m, i - 1, amt[i - 1]);
    return dp[m][i][x];
}

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
        cin>>n>>a>>b>>c>>d;
        reset();
        cout<<count(n, 3, amt[3])<<"\n";
    }
    return 0;
}