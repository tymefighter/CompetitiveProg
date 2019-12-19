#include<iostream>
#include<cmath>

using namespace std;

int n, a, b;

void solve()
{
    int h, h_vert;

    h = n - 1;
    h_vert = h - floor(log2(max(a, b)));

    cout<<(1 << (h + 1)) - (1 << (h_vert + 1)) + 1<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        solve();
    }
    return 0;
}