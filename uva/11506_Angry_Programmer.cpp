#include<iostream>
#include<queue>
#include<bitset>
#define INF 100000000

using namespace std;


/*
    In this problem we have to find the value of the
    capacity of a minimum cut which equals the 
    minimum cost of the edges which when removed
    disconnects the source and sink
*/

int res[105][105];
int p[105];
int s, t;
int M, W;
int n;

queue<int> q;
bitset<105> vs;

void reset()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        p[i] = -1;
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
}

void read()
{
    int i, j, w;
    for(int k = 0;k < M - 2;k++)
    {
        cin>>i>>w;
        i--;                                // Index starting from 0
        res[i][i + M] = w;
    }
    res[0][M] = INF;                        // cost of destroying the source or sink is infinity
    res[M - 1][2 * M - 1] = INF;

    for(int k = 0;k < W;k++)
    {
        cin>>i>>j>>w;
        i--, j--;                           // Index starting from 0
        res[i + M][j] = w;
        res[j + M][i] = w;
    }
}

int f;

void augment(int v, int minEdge)
{
    if(v == s)
        f = minEdge;
    else if(p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;                 // forward edge
        res[v][p[v]] += f;                 // backward edge
    }
}

void bfs()
{
    vs.reset();
    while(!q.empty())
        q.pop();

    int u, v;
    vs[s] = true;
    q.push(s);

    while(! q.empty())
    {
        u = q.front(), q.pop();
        if(u == t)
            break;

        for(v = 0;v < n;v++)
        {
            if(res[u][v] > 0 && !vs[v])
            {
                vs[v] = true;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

void EdmondsKarp()
{
    int mf = 0;

    while(true)
    {
        f = 0;
        bfs();
        augment(t, INF);
        if(!f)
            break;
        mf += f;
    }


    cout<<mf<<"\n";
}

int main()
{
    while(cin>>M>>W)
    {
        if(!(M | W))
            break;
        n = 2 * M;
        s = 0;
        t = n - 1;

        reset();
        read();
        EdmondsKarp();
    }
    return 0;
}
