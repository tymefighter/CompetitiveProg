#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> dp, topo;
vector<bool> visited;
vector<vector<int> > a;

void reset()
{
    dp.clear();
    a.clear();
    visited.clear();
    topo.clear();

    dp.assign(n, 0);
    a.resize(n);
    visited.assign(n, false);
}

void read()
{
    int i ,j, m, x;
    for(i = 0;i < n;i++)
    {
        cin>>m;

        for(j = 0;j < m;j++)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }
}

void dfs(int u)
{
    visited[u] = true;
    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}

void t_sort()
{
    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            dfs(u);
    }
    
    reverse(topo.begin(), topo.end());
}

void solve()
{
    t_sort();

    dp[0] = 1;

    for(int u : topo)
    {
        for(int v : a[u])
            dp[v] += dp[u];
    }

    int ans = 0;

    for(int u = 0;u < n;u++)
    {
        if(a[u].size() == 0)
            ans += dp[u];
    }
    cout<<ans<<"\n";
}

int main()
{
    int ct = 0;
    while(cin>>n)
    {
        if(!n)
            break;
        if(ct)
            cout<<"\n";
        reset();
        read();
        solve();
        ct++;
    }
    return 0;
}