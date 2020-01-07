#include<iostream>
#include<cmath>

using namespace std;

long long a, b;

void solve()
{
    if(a > b)
        swap(a, b);

    long long n_opt = ceil((sqrt(1. + 8. * (b - a)) - 1.) / 2.0);

    for(int i = 0;i < 4;i++)
    {
        if((b - a + (n_opt * (n_opt + 1)) / 2) % 2 == 0)
        {
            cout<<n_opt<<"\n";
            return;
        }
        n_opt ++;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        solve();
    }
    return 0;
}