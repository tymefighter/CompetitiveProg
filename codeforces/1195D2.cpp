#include<iostream>
#include<cmath>
#define MOD 998244353

using namespace std;

int n;
int a[100005];
int ct[11];


void read()
{
    int i;
    cin>>n;

    for(i = 0;i < 11;i++)
        ct[i] = 0;

    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        ct[(int)log10(a[i]) + 1]++;
    }
}

long long int get_ans(long long int x)
{
    int nd = log10(x) + 1;
    long long int x1 = x, x2 = x, xmd1 = 0, xmd2;
    long long int val1 = 0, val2 = 0, val3 = 0;
    long long int pw1 = 1, pw2 = 1;
    long long int ans = 0;

    while(x1)
    {
        val3 = (val3 + (pw1 * (x1 % 10)) % MOD) % MOD;
        x1 /= 10;
        pw1 = (pw1 * 100) % MOD;
    }

    x1 = x, pw1 = 10;
    for(int i = 1;i <= 10;i++)
    {
        if(i != 1)
        {
            xmd1 = x1 % 10;
            x1 /= 10;
        }

        xmd2 = x2 % 10;
        x2 /= 10;

        if(nd > i)
        {
            val1 = (val1 + (pw1 * xmd1) % MOD) % MOD;
            val2 = (val2 + (pw2 * xmd2) % MOD) % MOD;

            if(i != 1)
                pw1 = (pw1 * 100) % MOD;
            pw2 = (pw2 * 100) % MOD;

            if(!ct[i])
                continue;
            ans = (ans + (ct[i] * ((((x1 * pw1) % MOD + val1) % MOD + ((x2 * pw2) % MOD + val2) % MOD) % MOD) % MOD)) % MOD;
        }
        else
        {
            if(!ct[i])
                continue;
            ans = (ans + (ct[i] * ((11 * val3) % MOD)) % MOD) % MOD;
        }
    }

    return ans;
}

void solve()
{
    long long int ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans = (ans + get_ans(a[i] * 1ll)) % MOD;
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}