#include<iostream>

using namespace std;

const int N = 1e5;
int eulerPhi[N + 1];
long long ans[N + 1];

void computeAns()
{
    for(int i = 0;i <= N;i++)
        eulerPhi[i] = i;

    ans[0] = ans[1] = 0;
    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }

        ans[i] = ans[i - 1] + (i - eulerPhi[i]);
    }
}

int main()
{
    computeAns();
    int t;
    scanf("%d", &t);
    for(int i = 1;i <= t;i++)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %lld\n", i, ans[n]);
    }
    return 0;
}