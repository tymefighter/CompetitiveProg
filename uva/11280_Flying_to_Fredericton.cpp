#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

const int N = 105;

int n, source, dest, dist[N][N];
map<string, int> m;
vector<vector<pair<int, int> > > a;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

void reset()
{
    a.clear();
    a.resize(n);
}

void read()
{
    int num_e, w;
    cin>>n;
    reset();

    string u, v;
    for(int i = 0;i < n;i++)
    {
        cin>>u;
        m[u] = i;
    }

    cin>>num_e;
    for(int i = 0;i < num_e;i++)
    {
        cin>>u>>v>>w;
        a[m[u]].push_back({w, m[v]});
    }
    
    source = m["Calgary"];
    dest = m["Fredericton"];
}

void resetAlgo()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            dist[i][j] = -1;
    }

    while(!pq.empty())
        pq.pop();
}

void Dijkstra(int stop_overs)
{
    pair<int, pair<int, int> > u;
    dist[source][stop_overs] = 0;
    u.first = 0;
    u.second = {source, stop_overs};
    pq.push(u);

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(u.second.first == dest)
        {
            printf("Total cost of flight(s) is $%d\n", dist[u.second.first][u.second.second]);
            return;
        }

        if(u.second.second < 0 || dist[u.second.first][u.second.second] < u.first)
            continue;
        
        for(auto v : a[u.second.first])
        {
            if(dist[v.second][u.second.second - 1] == -1
                || dist[u.second.first][u.second.second] + v.first < dist[v.second][u.second.second - 1])
            {
                dist[v.second][u.second.second - 1] = dist[u.second.first][u.second.second] + v.first;
                pq.push({dist[v.second][u.second.second - 1], {v.second, u.second.second - 1}});
            }
        }
    }

    printf("No satisfactory flights\n");
}

void solve()
{
    int q, stop_overs;
    cin>>q;
    while(q--)
    {
        cin>>stop_overs;
        resetAlgo();
        Dijkstra(min(stop_overs, n - 2) + 1);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        if(i > 1)
            printf("\n");
        printf("Scenario #%d\n", i);
        read();
        solve();
    }
    return 0;
}