#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class UnionFind
{
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

const int N = 205;
const int INF = 100000000;

int n, r, ct, start, destination;
UnionFind ufds;
vector<pair<int, pair<int, int> > > elist;
vector<vector<pair<int, int> > > mst;
map<string, int> m;
pair<int, int> pred[N];
bool vis[N];

void reset()
{
    ct = 0;
    ufds.reset(n);
    elist.clear();
    mst.clear();
    mst.resize(n);
    m.clear();

    for(int i = 0;i < n;i++)
    {
        pred[i] = {-1, -1};
        vis[i] = false;
    }
}

void read()
{
    int w;
    string u, v;
    for(int i = 0;i < r;i++)
    {
        cin>>u>>v>>w;
        if(m.find(u) == m.end())
            m[u] = ct ++;
        if(m.find(v) == m.end())
            m[v] = ct ++;
        
        elist.push_back({w, {m[u], m[v]}});
    }

    cin>>u>>v;
    if(m.find(u) == m.end())
        m[u] = ct ++;
    if(m.find(v) == m.end())
        m[v] = ct ++;
    start = m[u], destination = m[v];
}

void dfs(int u)
{
    vis[u] = true;

    for(auto v : mst[u])
    {
        if(!vis[v.first])
        {
            pred[v.first] = {u, v.second};
            dfs(v.first);
        }
    }
}

void solve()
{
    sort(elist.begin(), elist.end());
    reverse(elist.begin(), elist.end());

    for(auto e : elist)
    {
        if(!ufds.isSame(e.second.first, e.second.second))
        {
            mst[e.second.first].push_back({e.second.second, e.first});
            mst[e.second.second].push_back({e.second.first, e.first});
            ufds.unionSet(e.second.first, e.second.second);
        }
    }

    dfs(start);
    int u = destination, ans = INF;
    pair<int, int> parent = pred[u];

    while(parent.first != -1)
    {
        ans = min(ans, parent.second);
        u = parent.first;
        parent = pred[u];
    }

    printf("%d tons\n", ans);
}

int main()
{
    int sno = 1;
    while(cin>>n>>r)
    {
        if(!(n | r))
            break;
        reset();
        read();
        printf("Scenario #%d\n", sno);
        solve();
        cout<<"\n";
        sno ++;
    }
    return 0;
}