#include<iostream>
#include<algorithm>

using namespace std;

int a[100005], b[100005];
int n, m;
int mn, mx;

void read()
{
    int i;
    cin>>n>>m;

    mx = -1;
    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        if(mx == -1 || mx < a[i])
            mx = a[i];
    }

    mn = -1;
    for(i = 0;i < m;i++)
    {
        cin>>b[i];
        if(mn == -1 || b[i] < mn)
            mn = b[i];
    }

}

void solve()
{

    if(mn < mx)
    {
        cout<<"-1\n";
        return;
    }

    bool flag = false;
    int i;
    long long int ans = 0;
    sort(a, a + n);
    reverse(a, a + n);

    for(i = 0;i < m;i++)
    {
        ans += (b[i] * 1ll);
        if(a[0] == b[i])
            flag = true;
    }


    if(!flag)
    {
        ans += (a[0] * 1ll);
        ans += (m - 1) * (a[1] * 1ll);
    }
    else
        ans += m * (a[1] * 1ll);

    for(i = 2;i < n;i++)
        ans += m * (a[i] * 1ll);

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}