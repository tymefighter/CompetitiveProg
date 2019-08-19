#include<iostream>

using namespace std;

long long int x, y, z;

void solve()
{
    long long int r1 = x % z, r2 = y % z;
    long long int ans = (x + y) / z;

    if(ans == x / z + y / z)
    {
        cout<<ans<<" 0\n";
        return;
    }
    
    if(r1 <= r2)
        cout<<ans<<" "<<z - r2<<"\n";
    else
        cout<<ans<<" "<<z - r1<<"\n";
}

int main()
{
    cin>>x>>y>>z;
    solve();
    return 0;
}