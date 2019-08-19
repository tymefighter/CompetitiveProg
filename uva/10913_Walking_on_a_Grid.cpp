#include<iostream>
#define MIN -10000000


using namespace std;

int n, k;
int a[77][77];
int dp[77][77][6][3];
// The fourth state variable tells how
// did we enter the current state i.e.
// using left, right, or down action

void reset()
{
    int i, j, k, l;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k <= 5;k++)
            {
                for(l = 0;l < 3;l++) // 0: left, 1: right, 2: down
                    dp[i][j][k][l] = -1;
            }
        }
    }
}

void read()
{
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            cin>>a[i][j];
    }
}

bool check(int r, int c)
{
    if(r < 0 || c < 0 || r >= n || c >= n)
        return false;
    return true;
}

int solve(int r, int c, int n_left, int prev_a)
{

    if(n_left < 0)
        return MIN;

    if(r == n - 1 && c == n - 1)
        return 0;
    
    if(dp[r][c][n_left][prev_a] != -1)
        return dp[r][c][n_left][prev_a];

    int max_val = MIN;
    int next_left;
    if(prev_a == 2)
    {
        if(check(r, c - 1))
        {
            if(a[r][c - 1] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r, c - 1, next_left, 0) + a[r][c - 1]);
        }

        if(check(r, c + 1))
        {
            if(a[r][c + 1] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r, c + 1, next_left, 1) + a[r][c + 1]);
        }

        if(check(r + 1, c))
        {
            if(a[r + 1][c] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r + 1, c, next_left, 2) + a[r + 1][c]);
        }
    }
    else if(prev_a == 0)
    {
        if(check(r, c - 1))
        {
            if(a[r][c - 1] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r, c - 1, next_left, 0) + a[r][c - 1]);
        }

        if(check(r + 1, c))
        {
            if(a[r + 1][c] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r + 1, c, next_left, 2) + a[r + 1][c]);
        }
    }
    else if(prev_a == 1)
    {
        if(check(r, c + 1))
        {
            if(a[r][c + 1] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r, c + 1, next_left, 1) + a[r][c + 1]);
        }

        if(check(r + 1, c))
        {
            if(a[r + 1][c] < 0)
                next_left = n_left - 1;
            else
                next_left = n_left;

            max_val = max(max_val, solve(r + 1, c, next_left, 2) + a[r + 1][c]);
        }
    }

    dp[r][c][n_left][prev_a] = max_val;
    return max_val;
}

int main()
{
    int co = 1, ans;
    while(cin>>n>>k)
    {
        if(!(n | k))
            break;
        
        reset();
        read();

        if(a[0][0] >= 0)
            ans = solve(0, 0, k, 2);
        else
            ans = solve(0, 0, k - 1, 2);

        if(ans >= 0)
            printf("Case %d: %d\n", co, a[0][0] + ans);
        else
            printf("Case %d: impossible\n", co);
        
        co++;
    }
    return 0;
}