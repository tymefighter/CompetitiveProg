#include<iostream>

using namespace std;

const int N = 105, INF = 100000000;
int n, a[N], dp[N][N][N][3];
bool num_found[N + 1];

void reset()
{
    int i, j, k, l;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k < n;k++)
            {
                for(l = 0;l < 3;l++)
                    dp[i][j][k][l] = -1;
            }
        }
    }

    for(int i = 0;i <= n;i++)
        num_found[i] = false;
}

void read()
{
    cin>>n;
    reset();

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        num_found[a[i]] = true;
    }
}

int getVal(int i, int o, int e, int c)
{
    if((o <= 0 && c == 1) || (e <= 0 && c == 2))
        return INF;

    if(i == 0)
        return 0;

    if(dp[i][o][e][c] != -1)
        return dp[i][o][e][c];


    if(a[i] != 0)
    {
        if(a[i - 1] != 0)
            dp[i][o][e][c] = getVal(i - 1, o, e, 0) + (int)((a[i] % 2) != (a[i - 1] % 2));
        else
            dp[i][o][e][c] = min(getVal(i - 1, o, e, 1) + (int)((a[i] % 2) != 1),
                                getVal(i - 1, o, e, 2) + (int)((a[i] % 2) != 0));
        
        return dp[i][o][e][c];
    }

    if(a[i - 1] != 0)
    {
        if(c == 1)
            dp[i][o][e][c] = getVal(i - 1, o - 1, e, 0) + (int)(1 != (a[i - 1] % 2));
        else if(c == 2)
            dp[i][o][e][c] = getVal(i - 1, o, e - 1, 0) + (int)(0 != (a[i - 1] % 2));

        return dp[i][o][e][c];
    }

    if(c == 1)
        dp[i][o][e][c] = min(getVal(i - 1, o - 1, e, 1),
                            getVal(i - 1, o - 1, e, 2) + 1);
    else if(c == 2)
        dp[i][o][e][c] = min(getVal(i - 1, o, e - 1, 1) + 1,
                            getVal(i - 1, o, e - 1, 2));


    return dp[i][o][e][c];
}

void solve()
{
    int odd = 0, even = 0;
    for(int i = 1;i <= n;i++)
    {
        if(!num_found[i])
        {
            if(i % 2)
                odd ++;
            else
                even ++;
        }
    }

    int ans = 0;
    if(a[n - 1] != 0)
        ans = getVal(n - 1, odd, even, 0);
    else
        ans = min(getVal(n - 1, odd, even, 1), getVal(n - 1, odd, even, 2));
    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}