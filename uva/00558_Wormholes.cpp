#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > a;
vector<int> dist;

void reset()
{
    a.clear();
    dist.clear();

    a.resize(n);
    dist.assign(n, -1);
}

void read()
{
    cin>>n>>m;
    reset();
    int x, y, w;
    for(int i = 0;i < m;i++)
    {
        cin>>x>>y>>w;
        a[x].push_back({y, w});
    }
}

void relax(int u, int v, int w)
{
    if(dist[v] == -1 || dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
}

bool BellmanFordCycle()
{
    int u;
    dist[u] = 0;
    for(int i = 0;i < n-1;i++)
    {
        for(u = 0;u < n;u++)
        {
            for(pair<int, int> v : a[u])
                relax(u, v.first, v.second);
        }
    }

    for(u = 0;u < n;u++)
    {
        for(pair<int, int> v : a[u])
        {
            if(dist[u] + v.second < dist[v.first])
                return true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        if(BellmanFordCycle())
            cout<<"possible\n";
        else
            cout<<"not possible\n";
    }
    return 0;
}