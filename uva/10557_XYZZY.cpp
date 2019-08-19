#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n;
vector<vector<pair<int, int> > > a;
vector<int> en, nen; // energy values of doors, negative of energy required
vector<bool> vis, vis_dfs;

void reset()
{
    a.clear();
    en.clear();
    nen.clear();
    vis.clear();
    vis_dfs.clear();

    a.resize(n);
    en.resize(n);
    nen.resize(n);
    vis.assign(n, false);
    vis_dfs.assign(n, false);
}

void read()
{
    int u, k, i, v;
    for(u = 0;u < n;u++)
    {
        cin>>en[u];
        cin>>k;
        for(i = 0;i < k;i++)
        {
            cin>>v;
            v--; // 0 to n-1 range
            a[u].push_back({v, -1});
        }
    }

    for(u = 0;u < n;u++)
    {
        for(i = 0;i < a[u].size();i++)
            a[u][i].second = -en[a[u][i].first]; // edge weight is equal to the energy of the door to be entered
    }
}

void relax(int u, int v, int w)
{
    if(vis[u] && (!vis[v] || nen[u] + w < nen[v]))
    {
        if(nen[u] + w >= 0) // energy cannot be negative
            return;
        
        nen[v] = nen[u] + w;
        vis[v] = true;
    }
}

void dfs(int u)
{
    vis_dfs[u] = true;

    for(pair<int, int> v : a[u])
    {
        if(!vis_dfs[v.first])
            dfs(v.first);
    }
}

bool BellmanFord()
{
    nen[0] = -100;
    vis[0] = true;
    int i, u, w;

    for(i = 0;i < n-1;i++)
    {
        for(u = 0;u < n;u++)
        {
            for(pair<int, int> v : a[u])
                relax(u, v.first, v.second);
        }
    }

    for(u = 0;u < n;u++)
    {
        for(pair<int, int> v : a[u])
        {
            if(vis[u] && vis[v.first] && nen[u] + v.second < nen[v.first])
            {
                dfs(u);
                if(vis_dfs[n-1])
                    return true;
            }
        }
    }

    if(vis[n-1])
        return true;
    else
        return false;
}

int main()
{
    while(cin>>n)
    {
        if(n == -1)
            break;
        reset();
        read();
        if(BellmanFord())
            cout<<"winnable";
        else
            cout<<"hopeless";
        cout<<"\n";
    }
    return 0;
}