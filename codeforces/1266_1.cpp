#include<iostream>

using namespace std;

long long x;

void solve()
{
    long long val;
    for(int i = 1;i <= 6;i++)
    {
        val = x - i;
        if(val > 0 && val % 14 == 0)
        {
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t --)
    {
        cin>>x;
        solve();
    }

    return 0;
}