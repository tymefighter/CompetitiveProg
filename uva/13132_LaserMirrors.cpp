#include<iostream>

using namespace std;

const int N = 100000;
int eulerPhi[N + 1];

void computePhi()
{
    for(int i = 0;i <= N;i++)
        eulerPhi[i] = i;

    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] != i)
            continue;
    
        for(int j = i;j <= N;j += i)
            eulerPhi[j] -= eulerPhi[j] / i;
    }
}

int main()
{
    int t;
    computePhi();
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n", eulerPhi[n]);
    }
    return 0;
}