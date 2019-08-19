#include<iostream>

using namespace std;

int n, x;
long long int dp[25][150];

void reset()
{
    int i, j;
    for(i = 0;i <= n;i++)
    {
        for(j = 0;j <= x;j++)
            dp[i][j] = -1;
    }
}

long long int pw(int i)
{
    if(i == 0)
        return 1;
    else if(i % 2)
        return 6 * pw(i - 1);
    else
    {
        long long int val = pw(i / 2);
        return val * val;
    }
}

long long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

long long int solve(int i, int sum)
{
    if(i == n + 1)
        return sum == x;
    
    if(dp[i][sum] != -1)
        return dp[i][sum];

    long long int ans = 0;
    for(int j = 1;j <= 6;j++)
        ans += solve(i + 1, min(sum + j, x));
    
    dp[i][sum] = ans;
    return ans;
}

void solve2()
{
    long long int val1 = solve(1, 0), val2 = pw(n);

    if(val1 % val2 == 0)
    {
        cout<<val1 / val2<<"\n";
        return;
    }

    long long int gcd_val = gcd(val1, val2);
    cout<<val1 / gcd_val<<"/"<<val2 / gcd_val<<"\n";
}

int main()
{
    while(cin>>n>>x)
    {
        if(!(n | x))
            break;
        reset();
        solve2();
    }
    return 0;
}