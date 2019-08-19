#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double d;

void solve()
{
    double a, b;

    if(d == 0)
    {
        printf("Y %0.9lf %0.9lf\n", 0., 0.);
        return;
    }

    if(d < 4)
    {
        cout<<"N\n";
        return;
    } 

    a = (d + sqrt(d * (d - 4))) / 2.0;
    b = d / a;

    if(b > a)
        swap(a, b);
    
    printf("Y %0.9lf %0.9lf\n", a, b);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>d;
        solve();
    }
    return 0;
}