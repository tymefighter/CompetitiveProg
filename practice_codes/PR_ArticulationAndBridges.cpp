#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, m, ct;
vector<vector<int> > a;
vector<int> dfs_num, dfs_low;
set<int> art;
set<pair<int, int> > br;

void reset()
{
    a.clear();
    a.resize(n);
    dfs_num.clear();
    dfs_num.assign(n, -1);
    dfs_low.clear();
    dfs_low.assign(n, -1);

    art.clear();
    br.clear();

    ct = 0;
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
    dfs_low[u] = dfs_num[u] = ct ++;

    for(int v : a[u])
    {
        if(dfs_low[v] == -1)
        {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            
            if(p != -1 && dfs_low[v] >= dfs_num[u])     // It should not be a root (p != -1)
                art.insert(u);
            
            if(dfs_low[v] > dfs_num[u])
                br.insert({u, v});
        }
        else if(v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(dfs_low[u] == -1)
        {
            dfs(u, -1);
            if(a[u].size() >= 2)
                art.insert(u);
        }
    }

    printf("Articulation pts: -\n");
    for(auto x : art)
        printf("%d\n", x);
    printf("Bridges: -\n");
    for(auto x : br)
        printf("(%d, %d)\n", x.first, x.second);
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