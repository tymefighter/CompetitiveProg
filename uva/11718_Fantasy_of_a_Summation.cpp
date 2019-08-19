#include<iostream>
#include<cstdio>

using namespace std;

int n, k, MOD;
int a[1001];

void read()
{
    cin>>n>>k>>MOD;
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int pow(int m)
{
    if(m == 0)
        return 1;
    if(m % 2)
        return ((pow(m - 1) % MOD) * n) % MOD;
    else
    {
        int val = pow(m / 2) % MOD;
        return (val * val) % MOD;
    }
}

void solve(int ct)
{
    int ans = 0;

    for(int i = 0;i < n;i++)
        ans = (ans + (a[i] % MOD)) % MOD;

    ans = ((((k % MOD) * pow(k - 1)) % MOD) * ans) % MOD;

    printf("Case %d: %d\n", ct, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}