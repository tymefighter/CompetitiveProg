#include<iostream>
#include<vector>

using namespace std;

int n;
long long int a[405];
long long int dp[405][405];
long long int sum[405][405];

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
            dp[i][j] = -1;
    }
}

void read()
{
    cin>>n;
    reset();
    int i, j, k;
    for(i = 0;i < n;i++)
        cin>>a[i];

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            sum[i][j] = 0;

            if(i <= j)
            {
                for(k = i;k <= j;k++)
                    sum[i][j] += a[k];
            }
            else
            {
                for(k = i;k < n;k++)
                    sum[i][j] += a[k];
                for(k = 0;k <= j;k++)
                    sum[i][j] += a[k];
            }
        }
    }
}

long long int solve(int l, int r)
{
    if(dp[l][r] != -1)
        return dp[l][r];

    if(l == r)
        return 0;

    if(r == (l + 1) % n)
        return a[l] + a[(l + 1) % n];
    
    bool first = true;
    long long int min_val, val;
    int k;
    if(l < r)
    {
        for(k = l;k < r;k++)
        {
            val = solve(l, k) + solve(k + 1, r) + sum[l][r];
            if(first || val < min_val)
            {
                min_val = val;
                first = false;
            }
        }
    }
    else
    {
        for(k = l;k <= n - 2;k++)
        {
            val = solve(l, k) + solve(k + 1, r) + sum[l][r];
            if(first || val < min_val)
            {
                min_val = val;
                first = false;
            }
        }

        val = solve(l, n - 1) + solve(0, r) + sum[l][r];
        if(first || val < min_val)
        {
            min_val = val;
            first = false;
        }

        for(k = 0;k < r;k++)
        {
            val = solve(l, k) + solve(k + 1, r) + sum[l][r];
            if(first || val < min_val)
            {
                min_val = val;
                first = false;
            }
        }
    }

    dp[l][r] = min_val;
    return min_val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long int ans;
    cin>>t;

    while(t--)
    {
        read();
        ans = solve((0 + 1) % n, 0);
        for(int i = 1;i < n;i++)
            ans = min(ans, solve((i + 1) % n, i));
        cout<<ans<<"\n";
    }
    return 0;
}