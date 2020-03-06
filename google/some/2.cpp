#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 100000000000000000

using namespace std;

int k, n;
int x[100005], c[100005];
long long int a[100005];

void read()
{
    cin>>k>>n;
    int i;
    for(i = 0;i < n;i++)
        cin>>x[i];
    for(i = 0;i < n;i++)
        cin>>c[i];
}

void solve(int case_no)
{
    long long int cost, val;
    int i, j, xpos;
    bool first = true;

    for(i = 0;i < n;i++)
    {
        val = c[i];
        xpos = x[i];
        for(j = 0;j < n;j++)
        {
            if(j != i)
                a[j] = (c[j] * 1ll) + abs(x[j] - xpos);
            else
                a[j] = MAX;
        }

        sort(a, a + n);
        for(j = 0;j < k;j++)
            val += a[j];

        if(first || val < cost)
        {
            cost = val;
            first = false;
        }
    }

    printf("Case #%d: %lld\n", case_no, cost);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}