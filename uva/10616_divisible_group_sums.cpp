#include<iostream>
#include<cstdio>


using namespace std;

int n, q;
int d, M;
long long int a[202];
long long int dp[202][12][22]; // index, left to pick, modulo sum

void reset()
{
    int i, j, k;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j < 12;j++)
        {
            for(k = 0;k < 22;k++)
                dp[i][j][k] = -1;
        }
    }
}

long long int count(int i, int m, int mod_sum)
{
    if(mod_sum < 0)
        mod_sum = d + mod_sum;

    if(dp[i][m][mod_sum] != -1)
        return dp[i][m][mod_sum];

    if(i == 0 && m != 0)
    {
        dp[i][m][mod_sum] = 0;
        return dp[i][m][mod_sum];
    }

    if(m == 0)
    {
        if(mod_sum == 0)
            dp[i][m][mod_sum] = 1;
        else
            dp[i][m][mod_sum] = 0;

        return dp[i][m][mod_sum];
    }

    dp[i][m][mod_sum] = count(i-1, m, mod_sum) + count(i-1, m-1, (mod_sum * 1ll + a[i]) % d);
    return dp[i][m][mod_sum];
}

void read_solve()
{
    int i;
    for(i = 1;i <= n;i++)
        cin>>a[i];
    
    for(i = 1;i <= q;i++)
    {
        reset();
        cin>>d>>M;
        printf("QUERY %d: %lld\n", i, count(n, M, 0));
    }
}

int main()
{
    int set_no = 1;
    while(cin>>n>>q)
    {
        if((n | q) == 0)
            break;
        printf("SET %d:\n", set_no);
        read_solve();

        set_no ++;
    }
    return 0;
}