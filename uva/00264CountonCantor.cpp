#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int n;

void solve()
{
    int x = (int)ceil((-1.0 + sqrt((float)(1 + 8 * n))) / 2.0);
    int val = n - (x * (x - 1)) / 2;
    
    if(x % 2)
        printf("TERM %d IS %d/%d\n", n, x + 1 - val, val);
    else
        printf("TERM %d IS %d/%d\n", n, val, x + 1 - val);
}

int main()
{
    while(cin>>n)
        solve();
    return 0;
}