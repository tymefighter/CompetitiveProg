#include<iostream>

using namespace std;

int n;
char a[105];

void solve()
{
    int ct = 0, ans = 0;

    for(int i = n - 1;i >= 0;i--)
    {
        if(a[i] == 'A')
        {
            ans = max(ans, ct);
            ct = 0;
        }
        else if(a[i] == 'P')
            ct ++;
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0;i < n;i++)
            cin>>a[i];
        solve();
    }
    return 0;
}