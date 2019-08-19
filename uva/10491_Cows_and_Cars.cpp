#include<iostream>
#include<cstdio>

using namespace std;

int n, ncow, ncar, nshow;
double ans;

void solve()
{
    n = ncow + ncar;
    ans = (ncar * (ncar + ncow - 1)) / (double) (n * (n - nshow - 1));
    printf("%.5lf\n", ans);
}

int main()
{
    while(cin>>ncow>>ncar>>nshow)
        solve();
    return 0;
}