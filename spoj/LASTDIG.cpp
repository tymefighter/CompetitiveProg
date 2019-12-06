#include<iostream>

using namespace std;

int mod_exp(const int &a, int n)
{
    if(n == 0)
        return 1;
    else if(n % 2)
        return (mod_exp(a, n - 1) * a) % 10;
    else
    {
        int val = mod_exp(a, n / 2);
        return (val * val) % 10;
    }
}

int main()
{
    int t, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a %= 10;
        cout<<mod_exp(a, b)<<"\n";
    }
    return 0;
}