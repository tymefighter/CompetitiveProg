#include<iostream>

using namespace std;

int p, x, mod;

int pow(int n)
{
    if(n == 0)
        return 1;

    if(n % 2)
        return (x * pow(n - 1)) % mod;
    else
    {
        int val = pow(n / 2);
        return (val * val) % mod;
    }
}

int main()
{
    while(cin>>x>>p>>mod)
    {
        x %= mod;
        cout<<pow(p)<<"\n";
    }
    return 0;
}