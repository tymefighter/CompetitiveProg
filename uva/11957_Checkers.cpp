#include<iostream>
#define MOD 1000007

using namespace std;

int n;
char a[101][101];
long long int dp[101][101];
int sr, sc;

void read()
{
    cin>>n;
    int i, j;
    for(i = n-1;i >= 0;i--)
    {
        for(j = 0;j < n;j++)
        {
            cin>>a[i][j];
            dp[i][j] = -1;
            if(a[i][j] == 'W')
            {
                sr = i, sc = j;
            }
        }
    }
}

bool check(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n || (a[r][c] == 'B'))
        return false;
    
    return true;
}

long long int count(int r, int c)
{
    if(r == n - 1)
        return 1;

    if(dp[r][c] != -1)
        return dp[r][c];
    long long int ans = 0;
    if(check(r + 1, c + 1))
        ans += count(r + 1, c + 1) % MOD;
    else if(check(r + 2, c + 2))
        ans += count(r + 2, c + 2) % MOD;

    ans = ans % MOD;

    if(check(r + 1, c - 1))
        ans += count(r + 1, c - 1) % MOD;
    else if(check(r + 2, c - 2))
        ans += count(r + 2, c - 2) % MOD;
    
    ans = ans % MOD;

    dp[r][c] = ans;
    return ans;
}


int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Case %d: %lld\n", i, count(sr, sc));
    }

    return 0;
}