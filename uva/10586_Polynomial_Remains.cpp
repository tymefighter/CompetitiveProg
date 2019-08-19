#include<iostream>

using namespace std;

int n, k;
long long int a[100005];

void read()
{
    for(int i = 0;i < n + 1;i++)
        cin>>a[i];
}

void solve()
{
    if(k > n)
    {
        for(int j = 0;j <= n;j++)
        {
            if(j)
                cout<<" ";
            cout<<a[j];
        }
        cout<<"\n";
        return;
    }

    int i;
    for(i = n;i >= k;i--)
    {
        a[i - k] -= a[i];
        a[i] = 0;
    }

    i = k - 1;
    while(i >= 0)
    {
        if(a[i])
            break;
        i--;
    }

    if(i == -1)
    {
        cout<<"0\n";
        return;
    }

    for(int j = 0;j <= i;j++)
    {
        if(j)
            cout<<" ";
        cout<<a[j];
    }
    cout<<"\n";
}

int main()
{
    while(cin>>n>>k)
    {
        if(n == -1 && k == -1)
            break;
        read();
        solve();
    }
    return 0;
}