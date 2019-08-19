#include<iostream>

using namespace std;

long long int x_val, k, a, b, d, fac, x_0, y_0;

void extendedEuclid()
{
    long long int x1, x2, y1, y2, r1, r2, r, q, x, y;

    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    r2 = a, r1 = b;

    while(r1 != 0)
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - q * x1;
        y = y2 - q * y1;

        x2 = x1, y2 = y1;
        x1 = x, y1 = y;
        r2 = r1;
        r1 = r;
    }

    x_0 = x2, y_0 = y2;
    d = r2;
}

void solve()
{
    if(x_val % k)
    {
        b = x_val / k;
        a = b + 1;
    }
    else
        b = a = x_val / k;
    extendedEuclid();
    fac = x_val / d;

    cout<<fac * y_0<<" "<<fac * x_0<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x_val>>k;
        solve();
    }
    return 0;
}