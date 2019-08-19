#include<iostream>
#include<cstdio>
#include<utility>
#include<cmath>

using namespace std;

pair<int, int> loc[13];
int dist[13][13];
int m, n, len;

int dp[13][3000];

int dst(int r1, int c1, int r2, int c2)
{
    return abs(r2 - r1) + abs(c2 - c1);
}

void read()
{
    cin>>m>>n;
    cin>>loc[0].first>>loc[0].second;

    cin>>len;
    len++;
    for(int i = 1;i < len;i++)
        cin>>loc[i].first>>loc[i].second;
}

void compute_pairwise()
{
    int i, j;
    for(i = 0;i < len;i++)
    {
        for(j = 0;j < len;j++)
        {
            dist[i][j] = dst(loc[i].first, loc[i].second, loc[j].first, loc[j].second);
            //cout<<i<<" "<<j<<" "<<dist[i][j]<<"--\n";
        }
    }
}

void reset()
{
    int i, j;
    for(i = 0;i <= 11;i++)
    {
        for(j = 0;j < 3000;j++)
            dp[i][j] = -1;
    }
}

int LSone(int x)
{
    return x & (-x);
}

int solve(int i, int s)
{
    if(dp[i][s] != -1)
        return dp[i][s];

    int temp = s - 1;

    if(temp - LSone(temp) == 0)
    {
        dp[i][s] = dist[0][i];
        return dp[i][s];
    }

    int min_val, val;
    bool first_min = true;

    int j, k;
    for(j = 1; j < len;j++)
    {
        if(j != i && (s & (1 << j)) != 0)
        {
            val = solve(j, s ^ (1 << i)) + dist[j][i];
            if(first_min == true || val < min_val)
            {
                first_min = false;
                min_val = val;
            }
        }
    }

    dp[i][s] = min_val;
    return min_val;
}

int get_ans()
{
    int i, val, ans;
    bool first_ans = true;
    for(i = 1;i < len;i++)
    {
        val = solve(i, (1 << len) - 1) + dist[i][0];
        if(first_ans == true || val < ans)
        {
            ans = val;
            first_ans = false;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        compute_pairwise();
        reset();
        printf("The shortest path has length %d\n",get_ans());
    }

    return 0;
}