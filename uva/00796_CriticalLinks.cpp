#include<iostream>
#include<vector>
#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

int n, vis_time;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> dfs_num, dfs_low, parent;
vector<pair<int, int> > edges;

void resetAll()
{
    visited.clear();
    visited.assign(n, false);
    adj.clear();
    adj.resize(n);
    dfs_num.clear();
    dfs_num.resize(n);
    dfs_low.clear();
    dfs_low.resize(n);
    parent.clear();
    parent.assign(n, -1);
    edges.clear();
    vis_time = 0;
}

void read()
{
    resetAll();


    int i, j, u, num_e, v;
    for(i = 0;i < n;i++)
    {
        scanf("%d (%d)", &u, &num_e);

        for(j = 0;j < num_e;j++)
        {
            cin>>v;
            adj[u].push_back(v);
        }
    }
}

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = vis_time++;
    visited[u] = true;

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            parent[v] = u;
            dfs(v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(dfs_low[v] > dfs_num[u])
            {
                if(u < v)
                    edges.push_back({u, v});
                else
                    edges.push_back({v, u});
            }
        }
        else
        {
            if(parent[u] != v)
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
        
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            dfs(u);
    }
}

void print_sol()
{
    printf("%d critical links\n", (int)edges.size());
    sort(edges.begin(), edges.end());

    for(pair<int, int> x : edges)
    {
        printf("%d - %d\n", x.first, x.second);
    }
}

int main()
{
    //int ct = 0;
    while(cin>>n)
    {
        //if(ct)
        //    cout<<"\n";
        
        read();
        solve();
        print_sol();
        //ct++;
        cout<<"\n";
    }
    return 0;
}