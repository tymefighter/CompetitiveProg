#include<iostream>

using namespace std;

const long long MOD = (long long) 1e9 + 7;

long long bin_exp(long long x, long long n)
{
    long long val = 1;
    while(n)
    {
        if(n & 1)
            val = (val * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return val;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n, ans;
        scanf("%lld", &n);

        switch(n) {
            case 1:
                ans = 1;
                break;
            case 2:
                ans = 2;
                break;
            default:
                switch (n % 3){
                    case 0:
                        ans = bin_exp(3, n / 3);
                        break;
                    case 1:
                        ans = (bin_exp(3, (n - 4) / 3) * 4) % MOD;
                        break;
                    case 2:
                        ans = (bin_exp(3, (n - 2) / 3) * 2) % MOD;
                        break;
                }
                break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}