#include<iostream>
#include<queue>
#include<bitset>
#define INF 1000000

using namespace std;

int res[2000][2000];
int p[2000];
char inp[31][31];
int mp[31][31];
int R, C, P, n;
int s, t;

queue<int> q;
bitset<2000> vs;

int ar[] = {0, 0, -1, 1};
int ac[] = {-1, 1, 0, 0};

/*
    In this problem, we must apply the techniques of
    vertex splitting and using a super source/sink
*/

void reset()
{
    int i, j;
    for(i = 0;i < 2000;i++)
    {
        p[i] = -1;
        for(j = 0;j < 2000;j++)
            res[i][j] = 0;
    }
}

bool is_valid(int r, int c)
{
    if(r >= 0 && r < R && c >= 0 && c < C)
        return true;
    else
        return false; 
}

void read()
{
    int i, j, ct = 0;
    for(i = 0;i < R;i++)
    {
        for(j = 0;j < C;j++)
        {
            cin>>inp[i][j];
            if(inp[i][j] == '~')
                continue;
            
            mp[i][j] = ct++;
        }
    }

    n = 2 * ct + 2;
    s = 2 * ct;
    t = 2 * ct + 1;



    for(i = 0;i < R;i++)
    {
        for(j = 0;j < C;j++)
        {
            if(inp[i][j] == '~')
                continue;
            
            if(inp[i][j] == '*')
            {
                res[s][mp[i][j]] = 1;
                res[mp[i][j]][mp[i][j] + ct] = 1;
            }
            else if(inp[i][j] == '.')
                res[mp[i][j]][mp[i][j] + ct] = 1;
            else if(inp[i][j] == '@')
                res[mp[i][j]][mp[i][j] + ct] = INF;
            else if(inp[i][j] == '#')
            {
                res[mp[i][j]][mp[i][j] + ct] = INF;
                res[mp[i][j] + ct][t] = P;
            }


            for(int k = 0;k < 4;k++)
            {
                int r = i + ar[k], c = j + ac[k];
                if(! is_valid(r, c) || (inp[r][c] == '~') || (inp[r][c] == '*'))
                    continue;

                res[mp[i][j] + ct][mp[r][c]] = INF;
                res[mp[r][c] + ct][mp[i][j]] = INF;
            }
        }
    }
}

int f;

void augment(int v, int minEdge)
{
    if(v == s)
        f = minEdge;
    else if(p[v] != -1)
    {
        augment(p[v], min(res[p[v]][v], minEdge));
        res[p[v]][v] -= f;  // front
        res[v][p[v]] += f;  // back
    }
}

void bfs()
{
    vs.reset();
    while(! q.empty())
        q.pop();
    
    int u, v;
    vs[s] = true;
    q.push(s);

    while(!q.empty())
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

int EdmondsKarp()
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

    return mf;
}

int main()
{
    while(cin>>R>>C>>P)
    {
        reset();
        read();
        cout<<EdmondsKarp()<<"\n";
    }
    return 0;
}