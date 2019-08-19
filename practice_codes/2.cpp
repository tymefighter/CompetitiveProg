#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>

using namespace std;

int n, m, ct;
vector<vector<int> > a;
vector<int> dfs_low, dfs_num;
vector<pair<int, int> > e;


void reset()
{
    a.clear();
    a.resize(n);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    dfs_num.clear();
    dfs_num.assign(n, -1);
}

void read()
{
    cin>>n>>m;
    reset();
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u, int p)
{
    dfs_low[u] = dfs_num[u] = ct++;

    for(int v : a[u])
    {
        if(dfs_num[v] == -1)
        {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(dfs_low[v] > dfs_num[u])
                e.push_back({u, v});
        }
        else if(v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void solve()
{
    ct = 0;
    for(int u = 0;u < n;u++)
    {
        if(dfs_num[u] == -1)
            dfs(u, 0);
    }

    for(pair<int, int> edge : e)
        printf("(%d, %d)\n", edge.first, edge.second);
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