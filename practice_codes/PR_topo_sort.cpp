#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<int> indeg, topo, topo_kahn;
vector<bool> visited;

void reset()
{
    a.clear();
    a.resize(n);
    indeg.clear();
    indeg.assign(n, 0);
    visited.clear();
    visited.assign(n, false);
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();

    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        indeg[v] ++;
    }
}

void dfs_t_sort(int u)
{
    visited[u] = true;
    for(int v : a[u])
    {
        if(!visited[v])
            dfs_t_sort(v);
    }

    topo.push_back(u);
}

void t_sort()
{
    topo.clear();
    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            dfs_t_sort(u);
    }

    reverse(topo.begin(), topo.end());
}

queue<int> q;

void kahn()
{
    topo_kahn.clear();
    for(int u = 0;u < n;u++)
    {
        if(!indeg[u])
            q.push(u);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_kahn.push_back(u);
        
        for(int v : a[u])
        {
            indeg[v] --;
            if(indeg[v] == 0)
                q.push(v);
        }
    }
}

void solve()
{
    t_sort();
    kahn();

    for(int u : topo)
        printf("%d ", u);
    printf("\n");

    for(int u : topo_kahn)
        printf("%d ", u);
    printf("\n");
}

int main()
{
    read();
    solve();
    return 0;
}