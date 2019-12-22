#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 505;
int n, m, s, t;
vector<vector<pair<int, int> > > a;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
int dist[N][2];

void reset()
{
    a.clear();
    a.resize(n);
    while(!pq.empty())
        pq.pop();
    s = 0, t = n - 1;

    for(int i = 0;i < n;i++)
        dist[i][0] = dist[i][1] = -1;
}

void read()
{
    int u, v, w;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        if(u == s && v == t)
            continue;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
}

// (u, 0): Reached u by walking, (u, 1): Reached v by cycling

void solve()
{
    dist[s][1] = 0;
    pq.push({0, {s, 1}});

    while(!pq.empty())
    {
        auto u = pq.top();
        pq.pop();

        if(u.second.first == t
            && u.second.second == 1)
            break;

        if(dist[u.second.first][u.second.second] < u.first)
            continue;
        
        for(pair<int, int> v : a[u.second.first])
        {
            int ds = dist[u.second.first][u.second.second] + v.first;

            if(dist[v.second][1 - u.second.second] == -1
                || ds < dist[v.second][1 - u.second.second])
            {
                dist[v.second][1 - u.second.second] = ds;
                pq.push({ds, {v.second, 1 - u.second.second}});
            }
        }
    }

    if(dist[t][1] == -1)
        cout<<"?\n";
    else
        cout<<dist[t][1]<<"\n";
}

int main()
{
    int ct = 1;
    while(cin>>n>>m)
    {
        reset();
        read();
        printf("Set #%d\n", ct);
        solve();
        ct ++;
    }
    return 0;
}