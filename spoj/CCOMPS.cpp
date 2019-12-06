#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<bool> visited;

void read()
{
    cin>>n>>m;
    a.resize(n);
    visited.assign(n, false);

    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
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
}

void solve()
{
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(!visited[i])
        {
            ans ++;
            dfs(i);
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}