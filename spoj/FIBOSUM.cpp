#include<iostream>

using namespace std;

const int MOD = 1000000007;
long long int a[2][2], b[2][2], P[2][2] = {{0, 1}, {1, 1}};

void multiply(long long c[2][2], long long d[2][2])
{
    a[0][0] = c[0][0], a[0][1] = c[0][1], a[1][0] = c[1][0], a[1][1] = c[1][1];
    b[0][0] = d[0][0], b[0][1] = d[0][1], b[1][0] = d[1][0], b[1][1] = d[1][1];

    c[0][0] = ((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD) % MOD;
    c[0][1] = ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD) % MOD;
    c[1][0] = ((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[1][0]) % MOD) % MOD;
    c[1][1] = ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD) % MOD;
}

void power(long long F[2][2], int n)
{
    if(n == 0)
    {
        F[0][0] = F[1][1] = 1;
        F[1][0] = F[0][1] = 0;
        return;
    }

    if(n % 2)
    {
        power(F, n - 1);
        multiply(F, P);
    }
    else
    {
        power(F, n / 2);
        multiply(F, F);
    }
}

long long int f[2][2];

long long fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;

    power(f, n - 1);
    return f[1][1];
}

long long sumFib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;

    return (fib(n + 2) - 1) % MOD;
}

int n, m;

void solve()
{
    long long ans = sumFib(m);
    if(n > 0)
        ans = (ans - sumFib(n - 1)) % MOD;
    
    if(ans < 0)
        ans += MOD;

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        solve();
    }
    return 0;
}