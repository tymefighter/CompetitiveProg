#include<iostream>
#include<vector>

using namespace std;

int n;
int b[5005], dp[5005][5005];
vector<int> a;

void reset()
{
    int i, j, k;

    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= n;j++)
        {
            dp[i][j] = -1;
        }
    }
}

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
        cin>>b[i];

    a.push_back(b[0]);
    for(int i = 1;i < n;i++)
    {
        if(b[i] != b[i - 1])
            a.push_back(b[i]);
    }
    n = a.size();
    reset();
}

int solve(int l, int r)
{
    if(dp[l][r] != -1)
        return dp[l][r];

    if(l == r)
    {
        dp[l][r] = 0;
        return 0;
    }

    dp[l][r] = min(solve(l + 1, r), solve(l, r - 1));
    
    if(a[l] != a[r])
        dp[l][r] ++;

    return dp[l][r];
}

int main()
{

    read();
    cout<<solve(0, n - 1)<<"\n";
    return 0;
}