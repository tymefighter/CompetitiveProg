#include<iostream>
#include<cmath>

using namespace std;

int n, k;

long long int mod_exp(const int &n, int k, const int &mod)
{
    if(k == 0)
        return 1;
    else if(k % 2)
        return (mod == 0 ? mod_exp(n, k - 1, mod) * n : (mod_exp(n, k - 1, mod) * n) % mod);
    else
    {
        long long int val = mod_exp(n, k / 2, mod);
        return (mod == 0 ? val * val : (val * val) % mod);
    }
}

void solve()
{
    double val = k * log10(n);
    int leading = floor(pow(10, val - floor(val) - 1) * 1000);
    int trailing = mod_exp(n, k, 1000);

    printf("%03d...%03d\n", leading, trailing);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        solve();
    }
    return 0;
}