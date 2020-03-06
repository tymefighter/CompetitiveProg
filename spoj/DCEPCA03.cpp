#include<iostream>

using namespace std;

const int N = 1e4 + 1;
int eulerPhi[N + 1];
long long eulerPhiSum[N + 1];

void computeVal()
{
    for(int i = 0;i <= N;i++)
        eulerPhi[i] = i;

    eulerPhiSum[0] = 0;
    eulerPhiSum[1] = 1;
    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }
        eulerPhiSum[i] = eulerPhiSum[i - 1] + eulerPhi[i];
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
        printf("%lld\n", eulerPhiSum[n] * eulerPhiSum[n]);
    }
    return 0;
}