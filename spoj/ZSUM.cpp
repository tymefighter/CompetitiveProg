#include<iostream>

using namespace std;

const long long MOD = 10000007;
long long n, k;

long long mod_exp(const long long &a, long long i)
{
    if(i == 0)
        return 1;
    else if(i % 2)
        return (mod_exp(a, i - 1) * a) % MOD;
    else
    {
        long long val = mod_exp(a, i / 2);
        return (val * val) % MOD;
    }
}

void solve()
{
    long long ans = 2 * mod_exp((n - 1) % MOD, k);

    ans = (ans + mod_exp(n % MOD, k)) % MOD;
    ans = (ans + 2 * mod_exp((n - 1) % MOD, n - 1)) % MOD;
    ans = (ans + mod_exp(n % MOD, n)) % MOD;

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>n>>k)
    {
        if(!(n | k))
            break;
        solve();
    }

    return 0;
}