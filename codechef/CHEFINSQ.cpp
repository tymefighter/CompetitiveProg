#include<iostream>
#include<algorithm>

using namespace std;

int n, k, minSum, totalSum;
int a[55];
long long int dp[55][55][5005];

void reset()
{
    int i, j, l;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= k;j++)
        {
            for(l = 0;l <= totalSum;l++)
                dp[i][j][l] = -1;
        }
    }
}

void read()
{
    cin>>n>>k;

    totalSum = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        totalSum += a[i];
    }

    sort(a, a + n);
    minSum = 0;

    for(int i = 0;i < k;i++)
        minSum += a[i];

    reset();
}

long long int solve(int i, int j, int sum)
{
    if(i == n && j == k && sum == minSum)
        return 1;

    if(i == n)
        return 0;
    
    if(dp[i][j][sum] != -1)
        return dp[i][j][sum];
    
    if(j == k)
        dp[i][j][sum] = solve(i + 1, j, sum);
    else
        dp[i][j][sum] = solve(i + 1, j, sum) + solve(i + 1, j + 1, sum + a[i]);

    return dp[i][j][sum];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        cout<<solve(0, 0, 0)<<"\n";
    }
    return 0;
}