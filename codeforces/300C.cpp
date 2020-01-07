#include<iostream>
#include<cmath>

using namespace std;

const long long MOD = 1e9 + 7;
long long ans, a, b, n, maxNo, fact_mod[1000005];

long long pw(long long x, long long y)
{
    if(y == 0)
        return 1;
    else if(y % 2)
        return (pw(x, y - 1) * x) % MOD;
    else
    {
        long long val = pw(x, y / 2);
        return (val * val) % MOD;
    }
}

bool isGood(long long x)
{
    int dig;
    while(x)
    {
        dig = x % 10;
        if(dig != a && dig != b)
            return false;
        x /= 10;
    }
    return true;
}

void solve()
{
    if(a == b)
    {
        if(isGood(n * a))
            cout<<"1\n";
        else
            cout<<"0\n";
        return;
    }

    maxNo = 9 * n;
    ans = 0;

    fact_mod[0] = 1;
    for(int i = 1;i <= n;i++)
        fact_mod[i] = (fact_mod[i - 1] * i) % MOD;

    long long n1, n2, num = fact_mod[n], denom;
    for(int g = 1;g <= maxNo;g++)
    {
        if(!isGood(g))
            continue;
        
        if((n * b - g) % (b - a))
            continue;

        n1 = (n * b - g) / (b - a);
        
        
        if(n1 < 0 || n1 > n)
            continue;
        n2 = n - n1;

        denom = (fact_mod[n1] * fact_mod[n2]) % MOD;

        ans = (ans + (num * pw(denom, MOD - 2)) % MOD) % MOD;
    }

    cout<<ans<<"\n";
}

int main()
{
    cin>>a>>b>>n;
    solve();
    return 0;
}