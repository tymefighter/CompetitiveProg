#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

class UnionFind
{
    private:
    vector<int> rank, p;

    public:

    UnionFind(int n)
    {
        reset(n);
    }

    void reset(int n)
    {
        rank.assign(n, 0);
        p.resize(n);

        for(int i = 0;i < n;i++)
            p[i] = i;
    }

    int findSet(int x)
    {
        int repx = x, u;

        while(repx != p[repx])
            repx = p[repx];
        
        while(x != p[x])
        {
            u = p[x];
            p[x] = repx;
            x = u;
        }

        return repx;
    }

    bool isSame(int a, int b)
    {
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b)
    {
        a = findSet(a), b = findSet(b);

        if(rank[a] > rank[b])
            p[b] = a;
        else if(rank[a] < rank[b])
            p[a] = b;
        else
        {
            p[b] = a;
            rank[a] ++;
        }
    }
};

int n, m, q, max_edge;
vector<pair<int, pair<int, int> > > el;
UnionFind ufds(0);
vector<vector<pair<int, int> > > mst;
vector<bool> visited;

void reset()
{
    el.clear();
    mst.clear();
    visited.clear();

    el.resize(m);
    mst.resize(n);
    visited.assign(n, false);
    ufds.reset(n);
}

void read()
{
    int a, b, w;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        el[i] = {w, {a, b}};
    }
}

void kruskal()
{
    sort(el.begin(), el.end());

    int a, b, w;
    for(auto edge : el)
    {
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;

        if(ufds.isSame(a, b))
            continue;
        
        ufds.unionSet(a, b);
        mst[a].push_back({b, w});
        mst[b].push_back({a, w});
    }
}

bool dfs(int u, int &target)
{
    visited[u] = true;
    if(u == target)
        return true;

    for(pair<int, int> v : mst[u])
    {
        if(visited[v.first])
            continue;
        
        if(dfs(v.first, target))
        {
            max_edge = max(max_edge, v.second);
            return true;
        }
    }

    return false;
}

void solve()
{
    int a, b;
    for(int i = 0;i < q;i++)
    {
        cin>>a>>b;
        a--, b--;
        
        visited.clear();
        visited.assign(n, false);
        max_edge = -1;

        dfs(a, b);
        if(! visited[b])
        {
            cout<<"no path\n";
            continue;
        }

        cout<<max_edge<<"\n";
    }
}

int main()
{
    int c_no = 1;
    while(cin>>n>>m>>q)
    {
        if(!(n|m|q))
            break;
        if(c_no != 1)
            cout<<"\n";

        printf("Case #%d\n", c_no);
        reset();
        read();
        kruskal();
        solve();
        c_no++;
    }
    return 0;
}