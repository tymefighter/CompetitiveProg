#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

int n;
int dp[505][505];
string s;

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
            dp[i][j] = 0;
    }
}

void solve()
{
    string x, y;

    int i, p, j, k;

    for(p = 1;p <= n;p++)
        dp[1][p] = 1;

    for(i = 1;i <= n;i++)
    {
        for(p = 1;p <= i;p++)
        {
            x.clear();
            for(k = p;k <= i;k++)
            {
                x.push_back(s[k - 1]);
            }

            if(p < i)
                dp[i][p] += dp[i - 1][p];
            
            for(j = 1;j <= p - 1;j++)
            {
                y.clear();
                for(k = j;k <= p - 1;k++)
                {
                    y.push_back(s[k]);
                }
                if(y < x)
                    dp[i][p] += dp[p - 1][j];
            }
        }
    }

    int ans = 0;

    for(int i = 1;i <= n;i++)
        ans += dp[n][i];
    
    cout<<ans<<"\n";
}

int main()
{
    cin>>s;
    n = s.size();
    solve();
    return 0;
}