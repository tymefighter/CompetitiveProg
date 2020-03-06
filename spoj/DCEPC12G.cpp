#include<iostream>

using namespace std;

const int N = 1e7, MOD = 1e9 + 7;
int eulerPhi[N + 1], num_primes[N + 1];

void computeVal()
{
    for(int i = 0;i <= N;i++)
        eulerPhi[i] = i;
    
    num_primes[0] = num_primes[1] = 0;
    int max_val = 0;
    for(int i = 2;i <= N;i++)
    {
        num_primes[i] = num_primes[i - 1];
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;

            num_primes[i] ++;
        }
    }
}

int factorial(int n)
{
    int val = 1;
    for(int i = 2;i <= n;i++)
        val *= i;
    return val;
}

long long pw(long long x, long long n)
{
    if(n == 0)
        return 1;
    else if(n % 2)
        return (pw(x, n - 1) * x) % MOD;
    else
    {
        long long val = pw(x, n / 2);
        return (val * val) % MOD;
    }
}

int main()
{
    computeVal();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);

        printf("%lld\n", pw(eulerPhi[n], (factorial(max(0, num_primes[n] - eulerPhi[n])))));
    }

    return 0;
}