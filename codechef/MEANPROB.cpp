#include<iostream>

using namespace std;

const int N = 1000005;
int n, a[N], max_a, sum_n;

void read()
{
    cin>>n;
    max_a = 1;
    sum_n = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        max_a = max(max_a, a[i]);
        sum_n += a[i];
    }
}

void solve()
{
    for(int i = n;i <= max_a * n - 1;i++)
    {
        a[i] = sum_n / n;
        sum_n = sum_n + a[i] - a[i - n];
    }
    int q, x;
    cin>>q;
    while(q--)
    {
        cin>>x;
        x = min(x, max_a * n) - 1;
        cout<<a[x]<<"\n";
    }
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