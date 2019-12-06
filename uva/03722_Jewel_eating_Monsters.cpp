#include<iostream>

using namespace std;

long long mod_exp(const long long &a, long long n, const long long &mod)
{
    if(n == 0)
        return 1;
    else if(n % 2)
        return (mod_exp(a, n - 1, mod) * a) % mod;
    else
    {
        long long val = mod_exp(a, n / 2, mod);
        return (val * val) % mod;
    }
}

long long x, alpha, n, c;

void solve()
{
    long long val1 = (mod_exp(alpha, n, c) * (x % c)) % c;
    long long val2 = ((mod_exp(alpha, n, c) - 1) * mod_exp(alpha - 1, c - 2, c)) % c;
    val2 = (val2 * alpha) % c;

    long long ans = (val1 - val2) % c;
    if(ans < 0)
        ans += c;

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>x>>alpha>>n>>c)
    {
        if(!(x | alpha | n | c))
            break;
        
        solve();
    }
    return 0;
}