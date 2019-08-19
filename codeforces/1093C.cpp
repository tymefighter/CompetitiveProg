#include<iostream>

using namespace std;

int n, m;
long long int a[200005];

void read_solve()
{
    cin>>n;
    m = n / 2;

    long long int x, prev_low, prev_high;
    cin>>x;
    a[0] = prev_low = 0;
    a[n - 1] = prev_high = x;
    for(int i = 1;i < m;i++)
    {
        cin>>x;
        a[i] = max(prev_low, x - min(prev_high, x));
        a[n - i - 1] = x - a[i];
        prev_low = a[i], prev_high = a[n - i - 1];
    }

    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    read_solve();
    return 0;
}