#include<iostream>

using namespace std;

long long int n, m;

void solve()
{
    if(m >= n)
    {
        cout<<(m + n - 2) * m * n + 4 * ((n * (n + 1) * (6 * m - 2 * n + 2)) / 12 - m * n)<<"\n";
    }
    else
    {
        cout<<(m + n - 2) * m * n + 4 * ((m * (m + 1) * (6 * n - 2 * m + 2)) / 12 - n * m)<<"\n";
    }
}

int main()
{
    while(cin>>n>>m)
    {
        if(!(n | m))
            break;
        solve();
    }
    return 0;
}