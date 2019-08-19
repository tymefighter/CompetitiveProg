#include<iostream>

using namespace std;

int n;

void solve(int ct)
{
    if(n == 1)
    {
        printf("Case %d: 0\n", ct);
        return;
    }

    long long int val = ((n*1ll) * (n - 1)) / 2ll;

    if(val % 2)
        printf("Case %d: %lld/%d\n", ct, val, 2);
    else
        printf("Case %d: %lld\n", ct, val / 2ll);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n;
        solve(i);
    }

    return 0;
}