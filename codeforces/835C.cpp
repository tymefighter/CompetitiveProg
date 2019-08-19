#include<iostream>
#include<vector>

using namespace std;

int n, q, c;
int dp[15][105][105];
vector<int> star[105][105];

void reset()
{
    int i, j, k;
    for(i = 0;i < 105;i++)
    {
        for(j = 0;j < 105;j++)
        {
            star[i][j].clear();
            for(k = 0;k < 15;k++)
                dp[k][i][j] = 0;
        }
    }
}

void read()
{
    cin>>n>>q>>c;

    int i, j, k, x, y, si;
    for(i = 0;i < n;i++)
    {
        cin>>x>>y>>si;
        // s[x][y] = si;
        // star[x][y] = true;
        star[x][y].push_back(si);
    }

    int val;
    for(k = 0;k <= c;k++)
    {
        for(i = 0;i < 105;i++)
        {
            for(j = 0;j < 105;j++)
            {
                val = 0;
                
                for(int s : star[i][j])
                    val += (s + k) % (c + 1);

                dp[k][i][j] = val + (i > 0 ? dp[k][i - 1][j] : 0) + (j > 0 ? dp[k][i][j - 1] : 0) - ((i > 0 && j > 0) ? dp[k][i - 1][j - 1] : 0);
            }
        }
    }
}

void solve()
{
    int t, x1, y1, x2, y2, ans;
    for(int i = 0;i < q;i++)
    {
        cin>>t>>x1>>y1>>x2>>y2;
        t %= (c + 1);

        ans = dp[t][x2][y2] + dp[t][x1 - 1][y1 - 1] - (dp[t][x1 - 1][y2] + dp[t][x2][y1 - 1]);
        cout<<ans<<"\n";
    }

}



int main()
{
    reset();
    read();
    solve();
    return 0;
}