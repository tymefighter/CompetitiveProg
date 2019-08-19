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
    int nc;
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
        nc = n;
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

        if(a == b)
            return;
        
        nc--;
        
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

int n, m;
UnionFind ufds(0);
vector<pair<int, pair<int, int> > > el;
vector<pair<int, pair<int, int> > > picked;
int best, sbest;

void reset()
{
    el.clear();
    picked.clear();

    ufds.reset(n);
    el.resize(m);
    sbest = 100000000;
}

void read()
{
    cin>>n>>m;

    reset();

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
    best = 0;
    for(auto edge: el)
    {
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;

        if(ufds.isSame(a, b))
            continue;
        
        ufds.unionSet(a, b);
        best += w;
        picked.push_back({w, {a, b}});
    }
}

void kruskal2(int fa, int fb, int fw) // f: flagged
{
    ufds.reset(n);

    int a, b, w;
    int val = 0;

    for(auto edge: el)
    {
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;


        if(ufds.isSame(a, b) || (a == fa && b == fb && w == fw))
            continue;
        
        
        val += w;
        ufds.unionSet(a, b);
    }

    if(ufds.nc == 1)
        sbest = min(sbest, val);
}

void solve()
{
    kruskal();

    for(auto edge: picked)
        kruskal2(edge.second.first, edge.second.second, edge.first);
    
    cout<<best<<" "<<sbest<<"\n";
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

