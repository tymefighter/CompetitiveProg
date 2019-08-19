#include<iostream>
#include<bitset>
#include<queue>
#define INF 100000000

using namespace std;

int n, s, t, m, f;
int res[103][103];
int p[103];
bitset<103> vis;
queue<int> q;

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
    cin>>s>>t>>m;
    s--, t--;
    int a, b, w;

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        res[a][b] = res[b][a] = res[a][b] + w;
    }
}

void augment(int v, int minEdge)
{
    if(v == s)
        f = minEdge;
    else if(p[v] != -1)
    {
        augment(p[v], min(res[p[v]][v], minEdge));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int EdmondsKarp()
{
    int u, v, mf = 0;

    while(true)
    {
        f = 0;
        while(!q.empty())
            q.pop();

        vis.reset();
        vis[s] = true;
        q.push(s);

        while(!q.empty())
        {
            u = q.front(), q.pop();

            for(v = 0;v < n;v++)
            {
                if(res[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        augment(t, INF);
        if(f == 0)
            break;
        
        mf += f;
    }

    return mf;
}

int main()
{
    int c = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        printf("Network %d\n", c);
        reset();
        read();
        printf("The bandwidth is %d.\n\n", EdmondsKarp());
        c++; 
    }
    return 0;
}