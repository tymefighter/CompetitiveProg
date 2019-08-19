#include<iostream>

using namespace std;

int a[10];
int n;

void see_digits(int x)
{
    while(x)
    {
        a[x % 10]++;
        x /= 10;
    }
}

void solve()
{
    int i;
    for(i = 0;i < 10;i++)
        a[i] = 0;
    for(i = 1;i <= n;i++)
        see_digits(i);
    for(i = 0;i < 10;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve();
    }
    return 0;
}