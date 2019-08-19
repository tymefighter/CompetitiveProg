#include<iostream>
#define MOD 998244353

using namespace std;

int n;
long long int val;

long long int get_val(long long int x)
{
    long long int ans = 0, pw = 1;
    while(x)
    {
        ans += ((pw % MOD) * (x % 10)) % MOD;
        x /= 10;
        pw *= 100;
    }

    ans = (ans * 11) % MOD;

    return (n * ans) % MOD;
}

void read_solve()
{
    val = 0;
    long long int x;

    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        val = (val + get_val(x)) % MOD;
    }

    cout<<val<<"\n";
}

int main()
{
    read_solve();
    return 0;
}