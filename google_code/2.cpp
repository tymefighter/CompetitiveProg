#include<iostream>

using namespace std;

const int MAXH = 15, MAXW = 15, MAXK = 7;
int H, W, K, a[MAXH][MAXW];
long long dp[MAXH][MAXH][MAXW][MAXW][MAXK];

void init_dp()
{
    for(int r1 = 0;r1 < H;r1++)
    {
        for(int r2 = 0;r2 < H;r2++)
        {
            for(int c1 = 0;c1 < W;c1 ++)
            {
                for(int c2 = 0;c2 < W;c2 ++)
                {
                    for(int k = 0;k <= K;k++)
                        dp[r1][r2][c1][c2][k] = -1;
                }
            }
        }
    }
}

void read()
{
    scanf("%d %d %d", &H, &W, &K);
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < W;j++)
        {
            char c;
            scanf(" %c", &c);
            if(c == 'v')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    init_dp();
}

bool contains_strawberry(int r1, int r2, int c1, int c2)
{
    for(int i = r1;i <= r2;i++)
    {
        for(int j = c1;j <= c2;j++)
        {
            if(a[i][j] == 1)
                return true;
        }
    }

    return false;
}

long long compute_dp(int r1, int r2, int c1, int c2, int k)
{
    if(r1 == r2 && c1 == c2)
        return (k == 1 && a[r1][c1] == 1 ? 1 : 0);

    if(dp[r1][r2][c1][c2][k] != -1)
        return dp[r1][r2][c1][c2][k];

    if(k == 1)
    {
        if(contains_strawberry(r1, r2, c1, c2))
            return 1;
        else
            return 0;
    }

    long long val = 0;

    for(int r = r1;r <= r2 - 1;r++)
    {
        if(contains_strawberry(r1, r, c1, c2))
            val += compute_dp(r + 1, r2, c1, c2, k - 1);
    }

    for(int c = c1;c <= c2 - 1;c++)
    {
        if(contains_strawberry(r1, r2, c1, c))
            val += compute_dp(r1, r2, c + 1, c2, k - 1);
    }


    dp[r1][r2][c1][c2][k] = val;
    return val;
}

int main()
{
    int C;
    scanf("%d", &C);
    
    for(int i = 1;i <= C;i++)
    {
        read();
        printf("Case #%d: %lld\n", i, compute_dp(0, H - 1, 0, W - 1, K));
    }
    return 0;
}