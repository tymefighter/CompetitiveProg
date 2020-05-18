#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, t;
vector<vector<int> > g, g_rev;
vector<int> ds, dt;

void reset()
{
    g.clear();
    g.resize(n);
    g_rev.clear();
    g_rev.resize(n);
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();

    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    scanf("%d %d", &s, &t);
}

queue<int> q;

void BFS(int src, const vector<vector<int> > &a, vector<int> &dist)
{
    dist.clear();
    dist.assign(n, -1);

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    BFS(s, g, ds);
    BFS(t, g_rev, dt);

    printf("Edges along any sp: -\n");
    for(int u = 0;u < n;u++)
    {
        for(int v : g[u])
        {
            if(ds[u] != -1 && dt[v] != -1 && ds[u] + 1 + dt[v] == ds[t])
                printf("(%d, %d)\n", u, v);
        }
    }

    printf("Verts along any sp: -\n");
    for(int u = 0;u < n;u++)
    {
        if(ds[u] != -1 && dt[u] != -1 && ds[u] + dt[u] == ds[t])
            printf("%d\n", u);
    }
}

int main()
{
    read();
    solve();
    return 0;
}