#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<int> dist;

void clear_dist()
{
    dist.clear();
    dist.assign(n, -1);
}

void reset()
{
    a.clear();
    a.resize(n);
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

void dfs(int u)
{
    for(int v : a[u])
    {
        if(dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

// Diameter finding

void solve()
{
    clear_dist();
    dist[0] = 0;
    dfs(0);

    int start = -1;
    for(int u = 0;u < n;u++)
    {
        if(start == -1 || dist[start] < dist[u])
            start = u;
    }

    clear_dist();
    dist[start] = 0;
    dfs(start);

    int max_val = -1;

    for(int u = 0;u < n;u++)
        max_val = max(max_val, dist[u]);

    cout<<max_val<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}