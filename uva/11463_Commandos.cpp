#include<iostream>
#include<cstdio>
#define VAL 100000000

/*
    - We must go through all vertices
    - So, we would send a commando to each vertex via a shortest
    path from source to it, then take a shortest path from this
    vertex to the destination
    - The ans would be the max of the sum of the above over all
    vertices since the process would happen parallely
*/

using namespace std;

int n, m, s, d;
int dist[101][101];

void reset()
{
    int u, v;
    for(u = 0;u < n;u++)
    {
        for(v = 0;v < n;v++)
        {
            if(u == v)
                dist[u][u] = 0;
            else
                dist[u][v] = VAL;
        }
    }
}

void read()
{
    cin>>n;
    reset();
    cin>>m;

    int a, b;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    cin>>s>>d;
}

int FW()
{
    int u, v, k;

    for(k = 0;k < n;k++)
    {
        for(u = 0;u < n;u++)
        {
            for(v = 0;v < n;v++)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
        }
    }

    int ans = 0;
    for(u = 0;u < n;u++)
        ans = max(ans, dist[s][u] + dist[u][d]);

    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Case %d: %d\n", i, FW());
    }
    return 0;
}