#include<iostream>
#include<vector>

using namespace std;

const int INF = (int)1e8;
int n, m, s;
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
    scanf("%d %d", &n, &m);
    reset();
    for(int i = 0;i < m;i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back({v, w});
    }
}

// returns false if there is a negative wt cycle,
// else returns true
bool BellmanFord()
{
    dist[s] = 0;

    for(int i = 0;i < n - 1;i++)
    {
        for(int u = 0;u < n;u++)
        {
            for(auto v : a[u])
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
        }
    }

    for(int u = 0;u < n;u++)
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
    if(BellmanFord())
    {
        for(auto d : dist)
            printf("%d ", d);
        printf("\n");
    }
    else
        printf("Negative cycle found\n");
}

int main()
{
    read();
    solve();
    return 0;
}