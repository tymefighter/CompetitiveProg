#include<iostream>

using namespace std;

int n, k;
int a[10005];

void read()
{
    cin>>n>>k;

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    int i, val = 0, max_val;
    for(i = 0;i < k;i++)
        val ^= a[i];
    
    max_val = val;

    for(;i < n;i++)
    {
        val ^= a[i - k];
        val ^= a[i];
        max_val = max(max_val, val);
    }

    cout<<max_val<<"\n";
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        read();
        solve();
    }

    return 0;
}