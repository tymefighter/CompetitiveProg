#include<iostream>
#include<string>

using namespace std;

const long long int MOD = 1000000007;
long long int dp[10005][105];
int d, n;
string s;

void reset()
{
    int i, val;

    for(i = 1;i <= n;i++)
    {
        for(val = 0;val < d;val++)
            dp[i][val] = 0;
    }

    for(val = 0;val <= 9;val++)
        dp[0][val % d] ++;
}

void solve()
{
    int i, j, val, dig;

    for(i = 1;i < n;i++)
    {
        for(val = 0;val < d;val++)
        {
            for(dig = 0;dig <= 9;dig++)
                dp[i][(val + dig) % d] = (dp[i][(val + dig) % d] + dp[i - 1][val]) % MOD;
        }
    }

    long long int ans = -1; // not counting 0
    int remain;
    val = 0;

    for(i = 0;i <= n - 2;i++)
    {
        for(j = 0;j <= (s[i] - '0') - 1; j++)
        {
            remain = (d - ((val + j) % d)) % d;
            ans = (ans + dp[n - i - 2][remain]) % MOD;
        }
        val = (val + (s[i] - '0')) % d;
    }

    for(j = 0;j <= (s[n - 1] - '0');j++)
    {
        remain = (d - ((val + j) % d)) % d;
        ans = (ans + ((val + j) % d == 0 ? 1 : 0)) % MOD;
    }

    cout<<ans<<"\n";
}

int main()
{
    cin>>s>>d;
    n = s.size();

    reset();
    solve();
    return 0;
}