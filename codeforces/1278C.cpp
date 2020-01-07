#include<iostream>
#include<map>

using namespace std;

const int N = 100005;
int n, r;
int a[N], b[N];
int x[N], y[N];
map<int, int> m;

void read()
{
    cin>>n;
    r = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        x[i] = y[i] = 0;
        if(a[i] == 1)
            r ++;
        else
            r --;
    }

    m.clear();
    for(int i = 0;i < n;i++)
    {
        cin>>b[i];
        if(b[i] == 1)
        {
            y[i] = (i > 0 ? y[i - 1] : 0) + 1;
            r ++;
        }
        else
        {
            y[i] = (i > 0 ? y[i - 1] : 0) - 1;
            r --;
        }
        if(m.find(y[i]) == m.end())
            m[y[i]] = i;
    }

    m[0] = -1;

    for(int i = n - 1;i >= 0;i--)
    {
        if(a[i] == 1)
            x[i] = (i < n - 1 ? x[i + 1] : 0) + 1;
        else
            x[i] = (i < n - 1 ? x[i + 1] : 0) - 1;
    }
}

void solve()
{
    if(r == 0)
    {
        cout<<"0\n";
        return;
    }

    int ans = 2 * n, xi, yi;

    if(m.find(r) != m.end())
        ans = min(ans, m[r] + 1);

    for(int i = 0;i < n;i++)
    {
        xi = x[i];
        yi = r - xi;
        if(m.find(yi) == m.end())
            continue;
        
        ans = min(ans, (n - i) + (m[yi] + 1));
    }

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