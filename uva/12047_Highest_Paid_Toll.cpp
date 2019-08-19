#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int n, m, s, t, p;

vector<vector<pair<int, int> > > g, grev;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<int> ds, dt; // distances -- ds: from s, dt: to t

void reset()
{
    g.clear();
    grev.clear();
    ds.clear();
    dt.clear();

    g.resize(n);
    grev.resize(n);
    ds.assign(n, -1);
    dt.assign(n, -1);
}

void read()
{
    cin>>n>>m>>s>>t>>p;
    s--, t--;
    int a, b, w;

    reset();

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        g[a].push_back({b, w});
        grev[b].push_back({a, w});
    }
}

void relax1(int u, int v, int w)
{
    if(ds[v] == -1 || ds[u] + w < ds[v])
    {
        ds[v] = ds[u] + w;
        pq.push({ds[v], v});
    }
}

void Dijkstra1()
{
    ds[s] = 0;
    pq.push({0, s});
    pair<int, int> x;
    int d, u;

    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        d = x.first, u = x.second;

        if(ds[u] < d) // lazy deletion
            continue;

        for(pair<int, int> v : g[u])
            relax1(u, v.first, v.second);
    }
}

void relax2(int u, int v, int w)
{
    if(dt[v] == -1 || dt[u] + w < dt[v])
    {
        dt[v] = dt[u] + w;
        pq.push({dt[v], v});
    }
}

void Dijkstra2()
{
    dt[t] = 0;
    pq.push({0, t});
    pair<int, int> x;
    int d, u;

    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        d = x.first, u = x.second;

        if(dt[u] < d)
            continue;

        for(pair<int, int> v : grev[u])
            relax2(u, v.first, v.second);
    }
}

void solve()
{
    Dijkstra1();
    Dijkstra2();


    int wt, max_val = -1;

    for(int u = 0;u < n;u++)
    {
        for(pair<int, int> v : g[u])
        {
            wt = ds[u] + v.second + dt[v.first];
            if(ds[u] != -1 && dt[v.first] != -1 && wt <= p)
                max_val = max(v.second, max_val);
        }
    }

    cout<<max_val<<"\n";
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