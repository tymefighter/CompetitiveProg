#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int> > a;
vector<int> p;
vector<bool> visited;
int x, y;

void reset_vis()
{
    visited.clear();
    visited.assign(n, false);
}

void reset()
{
    a.clear();
    a.resize(n);
    p.clear();
    p.assign(n, -1);
}

void read()
{
    cin>>n>>x>>y;
    reset();
    x--, y--;
    int u, v;

    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void sp_xy(int u)
{
    visited[u] = true;
    if(u == y)
        return;

    for(int v : a[u])
    {
        if(!visited[v])
        {
            p[v] = u;
            sp_xy(v);
        }
    }
}

int ct;

void dfs(int u)
{
    ct++;
    visited[u] = true;
    
    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

void solve()
{
    reset_vis();
    sp_xy(x);

    reset_vis();
    int u = y, num1, num2;
    while(p[u] != -1)
    {
        visited[u] = true;
        u = p[u];
    }

    ct = 0;
    dfs(x);
    num1 = ct;

    ct = 0;
    dfs(y);
    num2 = ct;

    cout<<n * (n * 1ll) - n - num1 * (num2 * 1ll)<<"\n";
}



int main()
{
    read();
    solve();
    return 0;
}