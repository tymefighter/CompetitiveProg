#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    
    return gcd(b % a, a);
}

int main()
{
    int t, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(gcd(a, b) == 1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }
    return 0;
}