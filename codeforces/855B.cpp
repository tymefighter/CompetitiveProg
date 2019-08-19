#include<iostream>

using namespace std;

int n;
long long int p, q, r;
long long int a[100005];
long long int ls[100005], ss[100005], le[100005], se[100005];

void read()
{
    cin>>n>>p>>q>>r;
    int i;
    for(i = 0;i < n;i++)
    {
        cin>>a[i];
        ls[i] = (i > 0 ? max(ls[i - 1], a[i]) : a[i]);
        ss[i] = (i > 0 ? min(ss[i - 1], a[i]) : a[i]);
    }
    for(i = n - 1;i >= 0;i--)
    {
        le[i] = (i < n - 1 ? max(le[i + 1], a[i]) : a[i]);
        se[i] = (i < n - 1 ? min(se[i + 1], a[i]) : a[i]);
    }
}

void solve()
{
    long long int ans, val;
    bool first = true;

    for(int i = 0;i < n;i++)
    {
        val = q * (a[i] * 1ll);
        if(p < 0)
            val += p * (ss[i] * 1ll);
        else
            val += p * (ls[i] * 1ll);
        if(r < 0)
            val += r * (se[i] * 1ll);
        else
            val += r * (le[i] * 1ll);
        if(first)
        {
            ans = val;
            first = false;
        }
        
        ans = max(ans, val);
    }

    cout<<ans<<"\n";
}


int main()
{
    read();
    solve();
    return 0;
}