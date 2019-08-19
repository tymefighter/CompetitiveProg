#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
long long int dp[200005][10], dp2[4][2];
vector<vector<vector<long long int> > > card;

void resetDP()
{
    int x, y;
    for(x = 0;x <= n;x++)
    {
        for(y = 0;y < 10;y++)
            dp[x][y] = -100000000000000;
    }
}

void read()
{
    cin>>n;
    int i, j, k, c, d;
    card.resize(n);
    for(i = 0;i < n;i++)
    {
        cin>>k;
        card[i].resize(4);
        for(j = 0;j < k;j++)
        {
            cin>>c>>d;
            card[i][c].push_back(d);
        }

        for(c = 1;c <= 3;c++)
        {
            sort(card[i][c].begin(), card[i][c].end());
            reverse(card[i][c].begin(), card[i][c].end());
            if(c == 1)
            {
                while(card[i][c].size() > 3)
                    card[i][c].pop_back();
            }
            else
            {
                while(card[i][c].size() > 1)
                    card[i][c].pop_back();
            }
        }
    }

    resetDP();
}

void solve()
{
    int x, y, k;
    int next, flag;

    dp[0][0] = 0;

    for(x = 0;x <= n-1;x++)
    {
        for(k = 0;k <= 3;k++)
            dp2[k][0] = dp2[k][1] = -100000000000000;
        dp2[0][0] = 0; // picking none from the current turn

        if(card[x][1].size() == 3)
        {
            dp2[3][0] = card[x][1][0] + card[x][1][1] + card[x][1][2];
            dp2[3][1] = 2 * card[x][1][0] + card[x][1][1] + card[x][1][2];
        }

        if(card[x][2].size() == 1 && card[x][1].size() >= 1)
        {
            dp2[2][0] = max(dp2[2][0], card[x][2][0] + card[x][1][0]);
            dp2[2][1] = max(dp2[2][1], max(card[x][2][0], card[x][1][0]) + card[x][2][0] + card[x][1][0]);
        }
        if(card[x][1].size() >= 2)
        {
            dp2[2][0] = max(dp2[2][0], card[x][1][0] + card[x][1][1]);
            dp2[2][1] = max(dp2[2][1], 2 * card[x][1][0] + card[x][1][1]);
        }

        if(card[x][1].size() >= 1)
        {
            dp2[1][0] = max(dp2[1][0], card[x][1][0]);
            dp2[1][1] = max(dp2[1][1], 2 * card[x][1][0]);
        }
        if(card[x][2].size() == 1)
        {
            dp2[1][0] = max(dp2[1][0], card[x][2][0]);
            dp2[1][1] = max(dp2[1][1], 2 * card[x][2][0]);
        }
        if(card[x][3].size() == 1)
        {
            dp2[1][0] = max(dp2[1][0], card[x][3][0]);
            dp2[1][1] = max(dp2[1][1], 2 * card[x][3][0]);
        }


        for(y = 0;y < 10;y++)
        {
            for(k = 0;k <= 3;k++)
            {
                next = (y + k) % 10;
                if(y + k >= 10)
                    flag = true;
                else
                    flag = false;
                if(dp2[k][flag] >= 0)
                    dp[x+1][next] = max(dp[x+1][next], dp[x][y] + dp2[k][flag]);
            }
        }
    }

    long long int ans = -100000000000000;

    for(y = 0;y < 10;y++)
    {
        if(dp[n][y] >= 0)
            ans = max(ans, dp[n][y]);
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}