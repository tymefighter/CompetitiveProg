#include<iostream>

using namespace std;

const int N = 20, INF = 100000000;
int m, dist[20][20];

void reset()
{
    int i, j;

    for(i = 0;i < N;i++)
    {
        for(j = 0;j < N;j++)
            dist[i][j] = INF;
    }
}

void read()
{
    int i, j, v;

    for(j = 0;j < m;j++)
    {
        cin>>v;
        v --;
        dist[0][v] = dist[v][0] = 1;
    }

    for(i = 1;i < 19;i++)
    {
        cin>>m;
        for(j = 0;j < m;j++)
        {
            cin>>v;
            v --;
            dist[i][v] = dist[v][i] = 1;
        }
    }
}

void solve()
{
    int k, i, j;

    for(k = 0;k < N;k++)
    {
        for(i = 0;i < N;i++)
        {
            for(j = 0;j < N;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    cin>>m;

    int u, v;
    for(i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v --;
        printf("%2d to %2d: %d\n", u + 1, v + 1, dist[u][v]);
    }
}

int main()
{
    int ct = 1;
    while(cin>>m)
    {
        printf("Test Set #%d\n", ct);
        reset();
        read();
        solve();
        ct ++;
        printf("\n");
    }
    return 0;
}