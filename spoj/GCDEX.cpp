#include<iostream>

using namespace std;

const int N = 1000001;
int eulerPhi[N + 1];
long long gcd_sum[N + 1], dp[N + 1];

void computeAns()
{
    for(int i = 0;i <= N;i ++)
    {
        eulerPhi[i] = i;
        gcd_sum[i] = 0;
    }

    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }
    }

    dp[0] = 0;
    for(int i = 1;i <= N;i++)
    {
        for(int j = i;j <= N;j += i)
            gcd_sum[j] += i * (long long) eulerPhi[j / i];

        dp[i] = dp[i - 1] + gcd_sum[i] - (long long) i;
    }
}

int main()
{
    computeAns();
    int n;
    while(scanf("%d", &n))
    {
        if(!n)
            break;
        printf("%lld\n", dp[n]);
    }

    return 0;
}