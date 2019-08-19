#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cstdio>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > adj;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int s, e;

void reset()
{
    adj.clear();
    dist.clear();
    
    adj.resize(n);
    dist.assign(n, -1);
}

void read()
{
    cin>>n>>m>>s>>e;
    reset();
    int a, b, w;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
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

int Dijkstra()
{
    dist[s] = 0;
    pq.push({0, s});
    pair<int, int> x;
    int d, u;

    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        if(x.second == e)
            break;

        d = x.first, u = x.second;

        for(pair<int, int> v : adj[u])
            relax(u, v.first, v.second);
    }

    while(!pq.empty())
        pq.pop();
    
    return dist[e];
}

int main()
{
    int t, ans;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        ans = Dijkstra();
        if(ans == -1)
            printf("Case #%d: unreachable\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}