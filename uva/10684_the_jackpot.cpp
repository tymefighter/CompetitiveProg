#include<iostream>
#include<cstdio>

using namespace std;

int a[10001];
int n;

void read()
{
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int solve() // Kadane's algorithm
{
    int ans = -1001, sum = 0;

    for(int i = 0;i < n;i++)
    {
        sum += a[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }   

    return ans;
}

int main()
{
    int ans = 0;
    while(cin>>n)
    {
        if(n == 0)
            break;
        read();
        ans = solve();
        if(ans <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", ans);
    }

    return 0;
}