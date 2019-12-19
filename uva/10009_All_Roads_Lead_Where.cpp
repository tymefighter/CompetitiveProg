#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n, q;
vector<vector<int> > a;
vector<bool> vis;
map<string, int> m;
vector<char> remap;

void reset()
{
    a.clear();
    a.resize(n);
    m.clear();
    remap.clear();
}

void read()
{
    string u, v;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        if(m.find(u) == m.end())
        {
            m[u] = remap.size();
            remap.push_back(u[0]);
        }
        
        if(m.find(v) == m.end())
        {
            m[v] = remap.size();
            remap.push_back(v[0]);
        }
        
        a[m[u]].push_back(m[v]);
        a[m[v]].push_back(m[u]);
    }
}

vector<int> p;

void resetDFS()
{
    p.clear();
    p.assign(n, -1);
    vis.clear();
    vis.assign(n, false);
}

void printPath(int v)
{
    if(v == -1)
        return;
    printPath(p[v]);
    cout<<remap[v];
}

void dfs(int u)
{
    vis[u] = true;
    for(int v : a[u])
    {
        if(!vis[v])
        {
            p[v] = u;
            dfs(v);
        }
    }
}

void solve()
{
    string u, v;
    while(q--)
    {
        cin>>u>>v;
        resetDFS();
        dfs(m[u]);
        printPath(m[v]);
        cout<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n>>q;
        n ++;
        reset();
        read();
        solve();
    }
    return 0;
}