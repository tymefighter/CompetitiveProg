#include<iostream>
#include<algorithm>

using namespace std;

long long int a[3];

void read()
{
    for(int i = 0;i < 3;i++)
        cin>>a[i];
    
    sort(a, a + 3);
}

void solve()
{
    long long int x, y, z, r;
    if(a[1] - a[0] <= a[2] - a[1])
    {
        x = a[0];
        y = a[1];
        z = a[2];
    }
    else
    {
        x = a[1];
        y = a[2];
        z = a[0];
    }

    long long int val = y + z - x;

    if(val % 2 == 0)
        r = val / 2;
    else
        r = val / 2 + 1;

    cout<<min(x + r, y + z - r)<<"\n";
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