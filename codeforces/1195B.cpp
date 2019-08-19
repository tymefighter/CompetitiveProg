#include<iostream>
#include<cmath>

using namespace std;

long long int n, k;

void solve()
{
    long long int u = 2 * (n + k), x;

    x = (-3 + sqrt(9 + 4 * u)) / 2;
    cout<<n - x<<"\n";
}

int main()
{
    cin>>n>>k;
    solve();
    return 0;
}