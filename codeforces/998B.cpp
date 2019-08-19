#include<iostream>

using namespace std;

int dp[102][102], a[102];

int solve(int i, int m)
{

    if(dp[i][m] != -1)
        return dp[i][m];

    if(i == 0)
    {
        dp[0][m] = 0;
        return dp[0][m];
    }

    bool flag = false;
    int val, max_val = 0;
    int odd, even, j;
    odd = even = 0;

    for(j = i-1;j >= 1;j--)
    {
        if(a[j] % 2 == 0)
            even ++;
        else
            odd ++;
        
        if(odd == even && m >= abs(a[j] - a[j-1]))
        {
            val = solve(j, m - abs(a[j] - a[j-1])) + 1;
            max_val = max(val, max_val);
            flag = true;
        }
    }

    if(flag)
    {
        dp[i][m] = max_val;
        return dp[i][m];
    }

    if(a[0] % 2 == 0)
        even++;
    else
        odd++;

    if(even == odd)
    {
        dp[i][m] = 0;
        return dp[i][m];
    }


    return -100000000;
}

int main()
{
    int i, j, n, b;
    cin>>n>>b;
    
    for(j = 0;j <= b;j++)
        dp[n][j] = -1;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        for(j = 0;j <= b;j++)
            dp[i][j] = -1;
    }
    
    cout<<solve(n, b)<<'\n';
    

    return 0;
}