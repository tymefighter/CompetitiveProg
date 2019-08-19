#include<iostream>
#include<cstdio>

using namespace std;

void read_solve(int c)
{
    int n, x, ans;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(i == n / 2)
            ans = x;
    }
    printf("Case %d: %d\n", c, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
        read_solve(i);
    return 0;
}