#include<iostream>

using namespace std;

const int N = 202918039;
int eulerPhi[N], ans[N];

void computeAns()
{
    for(int i = 0;i <= N;i++)
    {
        eulerPhi[i] = i;
        ans[i] = -1;
    }

    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2;i <= N;i++)
    {
        if(eulerPhi[i] == i)
        {
            for(int j = i;j <= N;j += i)
                eulerPhi[j] -= eulerPhi[j] / i;
        }

        if(ans[eulerPhi[i]] == -1)
            ans[eulerPhi[i]] = i;
    }
}

int main()
{
    int t;
    computeAns();
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(ans[n] == -1)
            printf("-1\n");
        else
            printf("%d\n", ans[n]);
    }
    return 0;
}