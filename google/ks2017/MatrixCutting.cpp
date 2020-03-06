#include<iostream>

using namespace std;

const int N = 41;
int n, m, a[N][N];
long long dp[N][N][N][N];

void read()
{
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

long long compMin(int rst, int rend, int cst, int cend)
{
    long long val = a[rst][cst];
    for(int i = rst;i <= rend;i++)
    {
        for(int j = cst;j <= cend;j++)
            val = min(val, (long long) a[i][j]);
    }
    return val;
}

void resetDP()
{
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            for(int k = 0;k <= m;k++)
            {
                for(int l = 0;l <= m;l++)
                    dp[i][j][k][l] = -1;
            }
        }
    }
}

long long computeVal(int r, int rs, int c, int cs)
{
    if(rs == 1 && cs == 1)
        return 0;

    if(dp[r][rs][c][cs] != -1)
        return dp[r][rs][c][cs];

    long long max_val = 0;

    if(rs > 1)
    {
        for(int i = 1;i < rs;i++)
            max_val = max(max_val, computeVal(r, i, c, cs) + computeVal(r + i, rs - i, c, cs));
    }
    if(cs > 1)
    {
        for(int i = 1;i < cs;i++)
            max_val = max(max_val, computeVal(r, rs, c, i) + computeVal(r, rs, c + i, cs - i));
    }

    dp[r][rs][c][cs] = max_val + compMin(r, r + rs - 1, c, c + cs - 1);
    return dp[r][rs][c][cs];
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++)
    {
        read();
        resetDP();
        printf("Case #%d: %lld\n", i, computeVal(0, n, 0, m));
    }
    return 0;
}