#include<iostream>

using namespace std;

int a[200005];
int n;
int mn, mx; // min, max
long long int nmn, nmx; // no_min, no_max
long long int ans;

void read()
{
    cin>>n;
    mn = mx = -1;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(!i)
            mn = mx = a[i];
        
        if(a[i] < mn)
            mn = a[i];
        if(a[i] > mx)
            mx = a[i];
    }
}

void solve()
{

    nmn = nmx = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == mn)
            nmn++;
        if(a[i] == mx)
            nmx++;
    }

    if(mn == mx)
        ans = (nmn * (nmn - 1)) / 2;
    else
        ans = nmn * nmx;
}

int main()
{
    read();
    solve();
    cout<<mx - mn<<" "<<ans<<"\n";

    return 0;
}