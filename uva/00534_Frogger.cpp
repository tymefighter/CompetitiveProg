#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class UnionFind
{
    private:
    vector<int> p, rank;
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
        
        while(x != p[x])
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
const double INF = 1e+10;

int n;
bool vis[N];
UnionFind ufds;
pair<int, int> coords[N];
pair<int, double> pred[N];
vector<pair<double, pair<int, int> > > elist;
vector<vector<pair<int, double> > > mst;

void reset()
{
    elist.clear();
    mst.clear();
    mst.resize(n);
    ufds.reset(n);

    for(int i = 0;i < n;i++)
    {
        pred[i] = {-1, -1};
        vis[i] = false;
    }
}

double dist(int i, int j)
{
    double val = (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first);
    val += (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second);
    return sqrt(val);
}

void read()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        cin>>coords[i].first>>coords[i].second;

        for(j = 0;j < i;j++)
            elist.push_back({dist(i, j), {i, j}});
    }
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

    for(auto e : elist)
    {
        if(!ufds.isSame(e.second.first, e.second.second))
        {
            mst[e.second.first].push_back({e.second.second, e.first});
            mst[e.second.second].push_back({e.second.first, e.first});
            ufds.unionSet(e.second.first, e.second.second);
        }
    }

    dfs(0);
    int u = 1;
    double ans = -INF;
    pair<int, double> parent = pred[1];

    while(parent.first != -1)
    {
        ans = max(ans, parent.second);
        u = parent.first;
        parent = pred[u];
    }
    printf("Frog Distance = %0.3lf\n", ans);
}

int main()
{
    int sc_no = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        printf("Scenario #%d\n", sc_no);
        reset();
        read();
        solve();
        cout<<"\n";
        sc_no ++;
    }

    return 0;
}