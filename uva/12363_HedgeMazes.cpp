#include<iostream>
#include<vector>

using namespace std;

class UnionFind {
    private:
    vector<int> rank, p;
    public:
    
    void reset(int n)
    {
        rank.clear();
        rank.assign(n, 0);
        p.clear();
        p.resize(n);
        for(int i = 0;i < n;i++)
            p[i] = i;
    }

    int findSet(int x)
    {
        int repx = x, u;

        while(p[repx] != repx)
            repx = p[repx];

        while(p[x] != x)
        {
            u = p[x];
            p[x] = repx;
            x = u;
        }

        return repx;
    }

    bool isSame(int u, int v)
    {
        return findSet(u) == findSet(v);
    }

    void unionSet(int u, int v)
    {
        u = findSet(u), v = findSet(v);

        if(u == v)
            return;
        
        if(rank[u] > rank[v])
            p[v] = u;
        else if(rank[u] < rank[v])
            p[u] = v;
        else
        {
            p[v] = u;
            rank[u] ++;
        }
    }

};

int n, m, q, ct;
vector<vector<int> > a;
vector<int> dfs_num, dfs_low;
UnionFind ufds_bridges; // This is build on the graph made of only bridges

void reset()
{
    ct = 0;
    a.clear();
    a.resize(n);
    dfs_num.clear();
    dfs_num.assign(n, -1);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    ufds_bridges.reset(n);
}

void read()
{
    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs_bridge(int u, int parent)
{
    dfs_low[u] = dfs_num[u] = ct ++;
    
    for(int v : a[u])
    {
        if(v == parent)
            continue;

        if(dfs_num[v] == -1)
        {
            dfs_bridge(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if(dfs_low[v] > dfs_num[u])
                ufds_bridges.unionSet(u, v);
        }
        else
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(dfs_num[u] == -1)
            dfs_bridge(u, -1);
    }

    while(q --)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        s --, t --;
        if(ufds_bridges.isSame(s, t)) // s and t are connected using only bridges
            printf("Y\n");
        else
            printf("N\n");
    }
}

int main()
{
    while(scanf("%d %d %d", &n, &m, &q))
    {
        if(!(n | m | q))
            break;
        reset();
        read();
        solve();
        printf("-\n");
    }
    return 0;
}