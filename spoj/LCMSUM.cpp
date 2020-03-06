#include<iostream>

using namespace std;

const int N = 1000000;
int eulerPhi[N + 1];
long long ans[N + 1];

void computeAns()
{
    for(int i = 0;i <= N;i++)
    {
        eulerPhi[i] = i;
        ans[i] = 0ll;
    }

    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i) // prime
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }
    }

    ans[1] = 1;
    for(int i = 2;i <= N;i++)
    {
        for(int j = i;j <= N;j += i)
            ans[j] += i * (long long) eulerPhi[i];
    
        ans[i] = i + (ans[i] * i) / 2;
    }
}

int main()
{
    int t;
    computeAns();
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n", ans[n]);
    }

    return 0;
}