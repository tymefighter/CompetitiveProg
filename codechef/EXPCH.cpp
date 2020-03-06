#include<iostream>
#include<cassert>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e7 + 5;
int n;
char a[N];
long long dp[3 * N];

long long pw(const long long &x, int p)
{
    if(p == 0)
        return 1;
    else if(p % 2)
        return (pw(x, p - 1) * x) % MOD;
    else
    {
        long long val = pw(x, p / 2);
        return (val * val) % MOD;
    }
}

void read()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf(" %c", &a[i]);
}

void right_shift(int &r)
{
    r --;
    dp[r + 0] = 0;
}

void left_shift(int &r)
{
    r ++;
    dp[r + n] = 0;
}

void solve()
{
    for(int i = 0;i <= 3 * (n + 1);i++)
        dp[i] = 0;

    int r = n + 1;
    long long ans = 0;
    for(long long i = 0;i < n;i++)
    {
        if(a[i] == '(')
        {
            right_shift(r);
            dp[r + 1] = (dp[r + 1] + 1) % MOD;
        }
        else if(a[i] == ')')
        {
            long long val = dp[r + 0];
            left_shift(r);

            dp[r + 1] = (dp[r + 1] + val + 1) % MOD;
            ans = (ans + (((val + 1) % MOD) * (n - i)) % MOD) % MOD;
        }
        else
            dp[r + 0] ++;
    }

    long long div = ((n * ((long long)n + 1)) / 2ll) % MOD;
    ans = ((ans % MOD) * pw(div, MOD - 2)) % MOD;
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        read();
        solve();
    }

    return 0;
}