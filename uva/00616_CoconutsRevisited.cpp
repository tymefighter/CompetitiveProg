#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int n;

bool check(int k)
{
    int m = n;

    for(int i = 0;i < k;i++)
    {
        if((m - 1) % k != 0 || m <= 0)
            return false;
        m = ((m - 1) / k) * (k - 1);
    }

    if(m % k == 0)
        return true;
    return false;
}

int solve()
{
    for(int i = (int)ceil(sqrt(n));i > 1;i--)
    {
        if(check(i))
            return i;
    }

    return -1;
}

int main()
{
    int ans;
    while(cin>>n)
    {
        if(n < 0)
            break;
        ans = solve();
        if(ans == -1)
            printf("%d coconuts, no solution\n", n);
        else
            printf("%d coconuts, %d people and 1 monkey\n", n, ans);
    }
    return 0;
}