#include<iostream>
#include<vector>

using namespace std;

int n, q;
int m[3];
int N[100005][26], dp[253][253][253], a[100005];
vector<int> r[3];

void read()
{
    char x;
    cin>>n>>q;

    for(int i = 0;i < n;i++)
    {
        cin>>x;
        a[i] = x - 'a';
    }

    for(int i = 0;i < 3;i++)
    {
        r[i].clear();
        m[i] = 0;
    }
}

void preprocess()
{
    int i, j;

    for(j = 0;j < 26;j++)           // There is no position including this or ahead of this which contains char j
        N[n][j] = N[n + 1][j] = n;

    for(i = n - 1;i >= 0;i--)       // N[i][j] contains the index idx s.t idx >= i and a[idx] = j
    {
        for(j = 0;j < 26;j++)
            N[i][j] = N[i + 1][j];
        
        N[i][a[i]] = i;
    }
}

void updateDP(int rel)
{
    int i, j, minVal = n + 1;
    if(rel == 0)
    {

        for(i = 0;i <= m[1];i++)
        {
            for(j = 0;j <= m[2];j++)
            {
                minVal = N[dp[m[0] - 1][i][j]][r[0][m[0] - 1]];
                if(i > 0)
                    minVal = min(minVal, N[dp[m[0]][i - 1][j]][r[1][i - 1]]);
                
                if(j > 0)
                    minVal = min(minVal, N[dp[m[0]][i][j - 1]][r[2][j - 1]]);

                dp[m[0]][i][j] = minVal + 1;
            }
        }

    }
    else if(rel == 1)
    {
        for(i = 0;i <= m[0];i++)
        {
            for(j = 0;j <= m[2];j++)
            {
                minVal = N[dp[i][m[1] - 1][j]][r[1][m[1] - 1]];
                if(i > 0)
                    minVal = min(minVal, N[dp[i - 1][m[1]][j]][r[0][i - 1]]);
                
                if(j > 0)
                    minVal = min(minVal, N[dp[i][m[1]][j - 1]][r[2][j - 1]]);

                dp[i][m[1]][j] = minVal + 1;
            }
        }
    }
    else if(rel == 2)
    {
        for(i = 0;i <= m[0];i++)
        {
            for(j = 0;j <= m[1];j++)
            {
                minVal = N[dp[i][j][m[2] - 1]][r[2][m[2] - 1]];
                if(i > 0)
                    minVal = min(minVal, N[dp[i - 1][j][m[2]]][r[0][i - 1]]);
                
                if(j > 0)
                    minVal = min(minVal, N[dp[i][j - 1][m[2]]][r[1][j - 1]]);

                dp[i][j][m[2]] = minVal + 1;
            }
        }
    }
}

void solve()
{
    dp[0][0][0] = 0;
    int rel;
    char c, x;

    while(q--)
    {
        cin>>c>>rel;
        rel --;
        if(c == '+')
        {
            cin>>x;
            r[rel].push_back(x - 'a');
            m[rel] ++;
            updateDP(rel);
        }
        else
        {
            r[rel].pop_back();
            m[rel] --;
        }

        if(dp[m[0]][m[1]][m[2]] == n + 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}

int main()
{
    read();
    preprocess();
    solve();
    return 0;
}