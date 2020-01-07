#include<iostream>
#include<vector>
#include<cassert>
#include<map>

using namespace std;

const long long MOD = 998244353; 
map<int, long long> m;
vector<vector<int> > a;
long long n, k_mul, k[1000005];

void read()
{
    cin>>n;
    a.clear();
    a.resize(n);
    m.clear();

    k_mul = 1;
    for(int i = 0;i < n;i++)
    {
        cin>>k[i];
        k_mul = (k_mul * k[i]) % MOD;
        a[i].resize(k[i]);
        for(int j = 0;j < k[i];j++)
        {
            cin>>a[i][j];
            if(m.find(a[i][j]) == m.end())
                m[a[i][j]] = 0;
            m[a[i][j]] ++;
        }
    }
}

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

void solve()
{
    long long num = 0, denom = (((n * n) % MOD) * k_mul) % MOD, val;

    for(int i = 0;i < n;i++)
    {
        val = 0;
        for(int j = 0;j < k[i];j++)
        {
            val = (val + m[a[i][j]]) % MOD;
        }

        val = (val * ((k_mul * pw(k[i], MOD - 2)) % MOD)) % MOD;
        num = (num + val) % MOD;
    }

    long long ans = (num * pw(denom, MOD - 2)) % MOD;
    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}