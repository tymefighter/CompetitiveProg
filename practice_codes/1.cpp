#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, m, ct, num_ch;
vector<vector<int> > a;
vector<int> dfs_num, dfs_low;
set<int> art;

void reset()
{
    a.clear();
    a.resize(n);
    dfs_num.clear();
    dfs_num.assign(n, -1);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    art.clear();
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

            if(dfs_num[u] <= dfs_low[v] && p != -1)
                art.insert(u);
            if(p == -1)
                num_ch++;
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
        {
            num_ch = 0;
            dfs(u, -1);
            if(num_ch > 1)
                art.insert(u);
        }
    }

    for(int v : art)
        cout<<v<<" ";
    cout<<"\n";
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