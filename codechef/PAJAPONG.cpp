#include<iostream>

using namespace std;

long long int x, y, k;

void solve()
{
    long long int val = (x + y) / k;
    if(val % 2 == 0)
        cout<<"Chef\n";
    else
        cout<<"Paja\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k;
        solve();
    }
    return 0;
}