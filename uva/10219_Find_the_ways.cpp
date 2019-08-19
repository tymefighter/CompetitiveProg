#include<iostream>
#include<cmath>

using namespace std;

int n, k;

void solve()
{
    int i, j;
    double dig = 1;

    for(i = k + 1;i <= n;i++)
        dig = dig + log10((double)i / (i - k));

    cout<<floor(dig)<<"\n";
}

int main()
{
    while(cin>>n>>k)
        solve();
    return 0;
}