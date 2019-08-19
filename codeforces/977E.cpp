#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<bool> visited;

void reset()
{
    a.clear();
    a.resize(n);
    visited.clear();
    visited.assign(n, false);
}

void read()
{
    cin>>n>>m;
    reset();

    int x, y;
    for(int i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

bool is_cycle;

void dfs(int u)
{
    visited[u] = true;

    if(a[u].size() != 2)
        is_cycle = false;

    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

void solve()
{
    int ans = 0;
    for(int u = 0;u < n;u++)
    {
        is_cycle = true;
        if(!visited[u])
        {
            dfs(u);
            if(is_cycle)
                ans++;
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