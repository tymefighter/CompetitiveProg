#include<iostream>

long long a, n, p;

long long bin_exp(long long x, long long pw)
{
    if(pw == 0)
        return 1;
    else if(pw % 2)
        return (x * bin_exp(x, pw - 1)) % p;
    else
    {
        long long val = bin_exp(x, pw / 2);
        return (val * val) % p;
    }
}

void read_solve(int cno)
{
    scanf("%lld %lld %lld", &a, &n, &p);
    long long ans = a % p;
    for(int i = 2;i <= n;i++)
        ans = bin_exp(ans, (long long)i);

    printf("Case #%d: %lld\n", cno, ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++)
        read_solve(i);
    return 0;
}