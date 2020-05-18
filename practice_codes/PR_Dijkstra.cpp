#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s;
vector<vector<pair<int, int> > > a;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
vector<int> dist;

void reset()
{
    a.clear();
    a.resize(n);
    dist.clear();
    dist.assign(n, -1);
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();
    for(int i = 0;i < m;i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back({w, v});
    }
}

void Dijkstra()
{
    dist[s] = 0;
    pq.push({0, 0});

    while(!pq.empty())
    {
        pair<int, int> u = pq.top();
        pq.pop();

        if(u.first > dist[u.second])
            continue;
        
        for(pair<int, int> v : a[u.second])
        {
            if(dist[v.second] == -1 || dist[u.second] + v.first < dist[v.second])
            {
                dist[v.second] = dist[u.second] + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }

    for(auto d : dist)
        printf("%d ", d);
    printf("\n");
}

int main()
{
    read();
    Dijkstra();
    return 0;
}