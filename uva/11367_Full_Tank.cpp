#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, e, c;
vector<vector<pair<int, int> > > a;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
int p[1005], dist[1005][105];

void reset()
{
    a.clear();
    a.resize(n);
}

void read()
{
    for(int i = 0;i < n;i++)
        cin>>p[i];
    
    int u, v, fuel_req;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>fuel_req;
        a[u].push_back({v, fuel_req});
        a[v].push_back({u, fuel_req});
    }
}

void resetD()
{
    while(!pq.empty())
        pq.pop();
    
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j <= c;j++)
            dist[i][j] = -1;
    }
}

void Dijkstra()
{
    dist[s][0] = 0;
    pq.push({0, {s, 0}});

    while(!pq.empty())
    {
        pair<int, pair<int, int> > u = pq.top();
        pq.pop();

        if(u.second.first == e)
        {
            cout<<dist[u.second.first][u.second.second]<<"\n";
            return;
        }

        if(dist[u.second.first][u.second.second] < u.first)
            continue;
        
        for(pair<int, int> v : a[u.second.first])
        {
            if(v.second > u.second.second)
                continue;
            
            v.second = u.second.second - v.second;
            if(dist[v.first][v.second] == -1
                || dist[u.second.first][u.second.second] < dist[v.first][v.second])
            {
                dist[v.first][v.second] = dist[u.second.first][u.second.second];
                pq.push({dist[v.first][v.second], {v.first, v.second}});
            }
        }

        if(u.second.second < c)
        {
            pair<int, int> v;
            v.first = u.second.first;
            v.second = u.second.second + 1;
            if(dist[v.first][v.second] == -1
                || dist[u.second.first][u.second.second] + p[u.second.first] < dist[v.first][v.second])
            {
                dist[v.first][v.second] = dist[u.second.first][u.second.second] + p[u.second.first];
                pq.push({dist[v.first][v.second], {v.first, v.second}});
            }
        }
    }

    cout<<"impossible\n";
}

void solve()
{
    int q;
    cin>>q;

    while(q --)
    {
        cin>>c>>s>>e;
        resetD();
        Dijkstra();
    }
}

int main()
{
    cin>>n>>m;
    reset();
    read();
    solve();
    return 0;
}