#include<iostream>

using namespace std;

long long int pow(int n)
{
    if(!n)
        return 1;

    if(n % 2)
        return pow(n - 1) * 2ll;
    else
    {
        long long int val = pow(n / 2);
        return val * val;
    }
}

int main()
{
    int n;
    cin>>n;
    if(n % 2)
        cout<<0<<"\n";
    else
        cout<<pow(n / 2)<<"\n";
    return 0;
}