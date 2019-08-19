#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > a;
vector<int> dist, p;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


void reset()
{
    a.clear();
    a.resize(n);
    dist.clear();
    dist.assign(n, -1);
    p.clear();
    p.assign(n, -1);
    while(!pq.empty())
        pq.pop();
}

void read()
{
    cin>>n>>m;
    reset();
    int u, v, w;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back({v, w});
    }
}

void relax(int u, int v, int w)
{
    if(dist[v] == -1 || dist[u] + w < dist[v])
    {
        dist[v] = dist[u] + w;
        p[v] = u;
        pq.push({v, dist[v]});
    }
}

void Dijkstra()
{
    dist[0] = 0;
    pq.push({0, 0});

    pair<int, int> u;
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(u.second > dist[u.first])  // Lazy propagation -- very important
            continue;
        
        for(auto v : a[u.first])
            relax(u.first, v.first, v.second);
    }
}

void solve()
{
    Dijkstra();

    for(int u = 0;u < n;u++)
        cout<<dist[u]<<" ";
    cout<<"\n";
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