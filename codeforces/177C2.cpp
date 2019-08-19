#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a, b;
vector<bool> vis, dt;       // visited, don't take

void reset_vals()
{
    vis.clear();
    vis.assign(n, false);
    dt.clear();
    dt.assign(n, false);
}

void reset()
{
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(n);
}

void read()
{
    cin>>n;
    reset();
    int i, x, y;

    cin>>m;
    for(i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    cin>>m;
    for(i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        b[x].push_back(y);
        b[y].push_back(x);
    }
}

bool dfs(int u)
{
    bool flag = true;
    vis[u] = true;

    for(int v : b[u])
        dt[v] = true;
    
    for(int v : a[u])
    {
        if(dt[v])
            return false;
        if(!vis[v] && !dt[v])
            flag &= dfs(v);
    }

    return flag;
}

void solve()
{
    int i, u, val, ans = 0;
    for(i = 0;i < n;i++)
    {
        reset_vals();
        if(!dfs(i))
            continue;

        val = 0;
        for(u = 0;u < n;u++)
        {
            if(vis[u])
                val++;
        }
        ans = max(ans, val);
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}