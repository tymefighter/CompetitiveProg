#include<iostream>

using namespace std;

const int N = 100005;
int n, m, a[N], b[N];
bool seen[N];

void read()
{
    cin>>n>>m;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < m;i++)
    {
        cin>>b[i];
        seen[b[i]] = false;
    }
}

void solve()
{
    long long ans = 0;
    int idx = 0;
    for(int i = 0;i < m;i++)
    {
        if(seen[b[i]])
        {
            ans ++;
            continue;
        }
        
        int k = idx - i;
        while(!seen[b[i]])
        {
            seen[a[idx]] = true;
            idx ++;
            k ++;
        }

        k --;
        ans += 2ll * k + 1;
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