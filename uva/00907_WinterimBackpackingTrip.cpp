#include<iostream>
#define MAX 100000000

using namespace std;

int n, k;
int c_dist[605]; // cumulative distance
int dp[605][305];

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= k + 1;j++)
            dp[i][j] = -1;
    }
}

void read()
{
    c_dist[0] = 0;
    for(int i = 1;i <= n + 1;i++)
    {
        cin>>c_dist[i];
        c_dist[i] += c_dist[i - 1];
    }
}

int solve(int i, int nl)
{
    if(i == n + 1 && nl == 0)
        return 0;

    if(i >= n + 1 || nl <= 0)
        return MAX;

    if(dp[i][nl] != -1)
        return dp[i][nl];
    

    int min_val = MAX;

    for(int j = i + 1;j <= n + 1;j++)
        min_val = min(min_val, max(c_dist[j] - c_dist[i], solve(j, nl - 1)));

    dp[i][nl] = min_val;
    return min_val;
}

int main()
{
    int i, j;
    while(cin>>n>>k)
    {
        reset();
        read();
        cout<<solve(0, k + 1)<<"\n";
    }
    return 0;
}