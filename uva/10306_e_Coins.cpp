#include<iostream>
#include<cstdio>

using namespace std;

int dp[501][501];
int c[41], in[41];
int m, s, sq_s;

void reset()
{
    int i, j;
    for(i = 0;i <= s;i++)
    {
        for(j = 0;j <= s;j++)
            dp[i][j] = -1;
    }
}

void read()
{
    cin>>m>>s;
    sq_s = s * s; // square of e_mod
    for(int i = 0;i < m;i++)
        cin>>c[i]>>in[i];
}

int sq_e_mod(int a, int b)
{
    return (a * a) + (b * b);
}

int solve(int a, int b)
{
    if(sq_e_mod(a, b) > sq_s)
        return 100000000;
    

    if(dp[a][b] != -1)
        return dp[a][b];

    if(sq_e_mod(a, b) == sq_s)
    {
        dp[a][b] = 0;
        return dp[a][b];
    }
    
    int min_val = 100000000;

    for(int i = 0;i < m;i++)
    {
        min_val = min(min_val, solve(a + c[i], b + in[i]));
    }

    dp[a][b] = 1 + min_val;
    return dp[a][b];
}

int main()
{
    int t, val;
    cin>>t;

    while(t--)
    {
        read();
        reset();
        val = solve(0, 0);
        if(val >= 100000000)
            cout<<"not possible\n";
        else
            cout<<val<<"\n";
    }

    return 0;
}