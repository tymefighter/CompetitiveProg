#include<iostream>
#include<cmath>

using namespace std;

long long int n, c1, n1, c2, n2;
long long int d, fac;
long long int x_0, y_0, u;

void extendedEuclid(int a, int b)
{
    long long int x2, y2, x1, y1, r2, r1, r, q, x, y;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    r2 = a, r1 = b;

    while(r1 != 0)
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - x1 * q;
        y = y2 - y1 * q;

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
    extendedEuclid(n1, n2);
    if(n % d != 0)
    {
        cout<<"failed\n";
        return;
    }

    fac = n / d;
    long long int val1, val2;

    val1 = (long long int) floor((fac * y_0 * d) / (double)n1);
    val2 = (long long int) ceil(( - fac * x_0 * d) / (double)n2);

    if(val1 < val2)
    {
        cout<<"failed\n";
        return;
    }

    if(c1 * n2 >= c2 * n1)
        u = val2;
    else
        u = val1;

    long long int x = fac * x_0 + (n2 / d) * u;
    long long int y = fac * y_0 - (n1 / d) * u;

    cout<<x<<" "<<y<<"\n";
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        cin>>c1>>n1;
        cin>>c2>>n2;
        solve();
    }
    return 0;
}