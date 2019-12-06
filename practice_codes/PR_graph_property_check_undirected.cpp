#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<bool> visited;
set<pair<int, int> > back;

void reset()
{
    a.clear();
    a.resize(n);
    visited.clear();
    visited.assign(n, false);
    back.clear();
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

bool hasCycle;

void dfs(int u, int p)
{
    visited[u] = true;

    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v, u);
        else if(v != p)
        {
            hasCycle = true;
            back.insert({min(u, v), max(u, v)});
        }
    }
}

void solve()
{
    hasCycle = false;

    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            dfs(u, -1);
    }

    if(hasCycle)
    {
        printf("Back: -\n");

        for(auto x : back)
            printf("(%d, %d)\n", x.first, x.second);
    }
    else
        printf("Does not have any cycle\n");
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