#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int n, T, e;
vector<vector<pair<int, int> > > adj;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void reset()
{
    adj.clear();
    dist.clear();

    adj.resize(n);
    dist.assign(n, -1);
}

void read()
{
    int m, a, b, w;
    cin>>n>>e>>T>>m;
    e--;
    reset();

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        adj[b].push_back({a, w}); // reversing all edges
    }
}

void relax(int u, int v, int w)
{
    if(dist[v] == -1 || dist[u] + w < dist[v])
    {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
    }
}

void Dijkstra()
{
    dist[e] = 0;
    pq.push({0, e});
    pair<int, int> x;
    int d, u;

    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        d = x.first, u = x.second;
        if(d > dist[u])
            continue;
        for(pair<int, int> v : adj[u])
            relax(u, v.first, v.second);
    }

    int ans = 0;
    for(u = 0;u < n;u++)
    {
        if(dist[u] != -1 && dist[u] <= T)
            ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        read();
        Dijkstra();
    }

    return 0;
}