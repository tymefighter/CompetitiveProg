#include<iostream>
#include<vector>
#include<utility>

using namespace std;

const int INF = 100000000;
int n, m;
vector<vector<pair<int, int> > > a;
vector<int> dist;

void reset()
{
    a.clear();
    a.resize(n);
    dist.clear();
    dist.assign(n, INF);
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
    dist[v] = min(dist[v], dist[u] + w);
}

bool BellmanFord()
{
    int u;
    dist[0] = 0;

    for(int i = 0;i < n - 1;i++)
    {
        for(u = 0;u < n;u++)
        {
            for(auto v : a[u])
                relax(u, v.first, v.second);
        }
    }

    for(u = 0;u < n;u++)
    {
        for(auto v : a[u])
        {
            if(dist[u] + v.second < dist[v.first])
                return false;
        }
    }

    return true;
}

void solve()
{
    if(!BellmanFord())
    {
        cout<<"Has negative cycle\n";
        return;
    }

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