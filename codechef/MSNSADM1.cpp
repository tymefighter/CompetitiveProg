#include<iostream>

using namespace std;

int n;
int a[151];

void read_solve()
{
    int x;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        a[i] = 20 * x;
    }

    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        a[i] = max(a[i] - 10 * x, 0);
        ans = max(a[i], ans);
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        read_solve();
    return 0;
}