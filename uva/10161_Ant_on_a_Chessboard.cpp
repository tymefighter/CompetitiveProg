#include<iostream>
#include<cmath>

using namespace std;

long long int n, a, b;

void solve()
{
    long long int x, val;
    
    x = (int)sqrt(n);

    if(x * x == n)
    {
        if(x % 2)
        {
            a = 1;
            b = x;
        }
        else
        {
            a = x;
            b = 1;
        }
        return;
    }



    val = n - x * x;

    if(x % 2)
    {
        if(val > ((x + 1)*(x + 1) - x * x) / 2)
        {
            a = x + 1;
            b = 1 + ((x + 1)*(x + 1) - n);
        }
        else
        {
            a = n - x * x;
            b = x + 1;
        }
    }
    else
    {
        if(val > ((x + 1)*(x + 1) - x * x) / 2)
        {
            a = 1 + ((x + 1)*(x + 1) - n);
            b = x + 1;
        }
        else
        {
            a = x + 1;
            b = n - x * x;
        }
    }
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}