#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int t, m, n;
    cin>>t;

    while(t--)
    {
        cin>>m>>n;
        if(gcd(m, n) == 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}