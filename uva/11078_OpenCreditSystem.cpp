#include<iostream>

using namespace std;

const int INF = 100000000;
int n, a[100005], front_max[100005], back_min[100005];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        front_max[i] = (i > 0 ? max(front_max[i - 1], a[i]) : a[i]);
    }

    for(int i = n - 1;i >= 0;i--)
        back_min[i] = (i < n - 1 ? min(back_min[i + 1], a[i]) : a[i]);
}

void solve()
{
    int ans = -INF;
    for(int i = 0;i < n - 1;i++)
        ans = max(ans, front_max[i] - back_min[i + 1]);
    
    cout<<ans<<"\n";
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