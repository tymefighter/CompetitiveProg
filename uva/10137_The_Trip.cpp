#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int n;
int a[1005];


void read_solve()
{
    int neg, pos, sum, l_mean, h_mean, ans;
    int x, y;
    sum = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%d.%d", &x, &y);
        a[i] = 100 * x + y;
        sum += a[i];
    }

    l_mean = (int)floor(sum / (double)n);
    h_mean = (int)ceil(sum / (double)n);
    neg = pos = 0;

    for(int i = 0;i < n;i++)
    {
        if(a[i] < l_mean)
            neg += (l_mean - a[i]);
        else if(a[i] > h_mean)
            pos += (a[i] - h_mean);
    }

    ans = max(neg, pos);
    
    printf("$%d.%02d\n", ans / 100, (ans % 100));
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        read_solve();
    }
    
    return 0;
}