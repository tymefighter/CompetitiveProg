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

        while(p[x] != x)    // Path Compression
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

int n, m;
vector<pair<int, pair<int, int> > > elist;
UnionFind ufds;

void reset()
{
    elist.clear();
    elist.resize(m);
    ufds.reset(n);
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();

    for(int i = 0;i < m;i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        elist[i] = {w, {u, v}};
    }
}

void solve()
{
    sort(elist.begin(), elist.end());

    int wt = 0;
    for(auto e : elist)
    {
        if(!ufds.isSame(e.second.first, e.second.second))
        {
            wt += e.first;
            printf("(%d, %d): %d\n", e.second.first, e.second.second, e.first);
            ufds.unionSet(e.second.first, e.second.second);
        }
    }

    printf("Total wt: %d\n", wt);
}

int main()
{
    read();
    solve();
    return 0;
}