#include<iostream>
#include<cmath>

using namespace std;

int n, l, r;

void solve()
{
    int k = min(r, n);

    long long int minVal = pow(2, l) - 1 + (n - l);
    long long int maxVal = pow(2, k) - 1 + (n - k) * pow(2, k - 1);

    cout<<minVal<<" "<<maxVal<<"\n";
}

int main()
{
    cin>>n>>l>>r;
    solve();
    return 0;
}