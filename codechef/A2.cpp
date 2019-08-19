#include<iostream>
#include<cmath>

using namespace std;

bool solve()
{
    int n;
    long int s, l;
    cin>>n;

    cin>>l;
    s = 1 - l;
    if(s < 0)
        return false;
    
    for(int i = 1;i < n;i++)
    {
        cin>>l;
        s = 2*s - l;
        if(s < 0)
            return false;
    }

    if(s != 0)
        return false;

    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        if(solve())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}