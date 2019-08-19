#include<iostream>

using namespace std;

int n, q;
int a[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        a[i] += (i > 0 ? a[i - 1] : 0);
    }
}

void solve()
{
    cin>>q;

    int l, r;

    for(int i = 0;i < q;i++)
    {
        cin>>l>>r;
        l--, r--;
        cout<<(a[r] - (l > 0 ? a[l - 1] : 0)) / 10<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}