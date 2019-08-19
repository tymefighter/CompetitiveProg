#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n, m, ct, root, n_ch;
vector<vector<int> >adj;
vector<bool> visited;
vector<int> dfs_num, dfs_low, parent;
vector<pair<int, int> > p_val;

void resetAll()
{
    adj.clear();
    adj.resize(n);
    visited.clear();
    visited.assign(n, false);
    p_val.clear();
    p_val.assign(n, {1, 0});
    dfs_num.clear();
    dfs_num.assign(n, 0);
    dfs_low.clear();
    dfs_low.assign(n, 0);
    parent.clear();
    parent.assign(n, -1);
    ct = 0;
}

void read()
{
    int a, b;

    resetAll();
    while(cin>>a>>b)
    {
        if(a == -1 && b == -1)
            break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int u)
{
    visited[u] = true;
    dfs_low[u] = dfs_num[u] = ct++;

    for(int v : adj[u])
    {
        if(!visited[v])
        {
            //if(u == 0)
            //    cout<<"a\n";
            if(u == root)
                n_ch++;
            parent[v] = u;
            dfs(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if(u != root && dfs_low[v] >= dfs_num[u])
            {
                p_val[u].first++;
            }
        }
        else if(v != parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(b.first < a.first)
        return true;
    else if(b.first > a.first)
        return false;
    else if(b.second > a.second)
        return true;
    else
        return false;
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        p_val[u].second = u;
        
        if(!visited[u])
        {
            n_ch = 0;
            root = u;
            dfs(u);
            if(n_ch > 1)
                p_val[root].first = n_ch;
        }
    }

    sort(p_val.begin(), p_val.end(), comp);
    
    for(int i = 0;i < m;i++)
        cout<<p_val[i].second<<" "<<p_val[i].first<<"\n";

}

int main()
{
    while(cin>>n>>m)
    {
        if((n | m) == 0)
            break;
        read();
        solve();
        cout<<"\n";
    }

    return 0;
}