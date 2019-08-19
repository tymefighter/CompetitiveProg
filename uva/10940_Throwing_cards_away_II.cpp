#include<iostream>

using namespace std;

int n;

void solve()
{
    if(n == 1)
    {
        cout<<"1\n";
        return;
    }
    int x = 1;
    while(x * 2 < n)
        x *= 2;

    cout<<(n - x) * 2<<"\n";
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
    }
    return 0;
}