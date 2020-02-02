#include<iostream>
#include<cmath>

using namespace std;

long long n, d;

bool solve()
{
    if((n + 1) * (n + 1) >= 4 * d)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}