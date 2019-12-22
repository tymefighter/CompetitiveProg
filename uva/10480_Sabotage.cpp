#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int N = 55;
const long long INF = 1000000000000000;
int s, t, n, m;
long long res[N][N];
vector<pair<int, int> > actual_edge_list;

long long f;
int p[N];
bool vis[N];
queue<int> q;

bool isCapCityGrp[N];

void reset()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        isCapCityGrp[i] = false;
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
    actual_edge_list.clear();
    s = 0;
    t = 1;
}

void read()
{
    int u, v, w;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        u --, v --;
        res[u][v] += (long long)w;
        res[v][u] += (long long)w;
        actual_edge_list.push_back({u, v});
    }
}

void resetBFS()
{
    for(int i = 0;i < n;i++)
    {
        vis[i] = false;
        p[i] = -1;
    }

    while(!q.empty())
        q.pop();
}

void augment(int v, long long minEdge)
{
    if(v == s)
    {
        f = minEdge;
        return;
    }

    augment(p[v], min(minEdge, res[p[v]][v]));

    res[p[v]][v] -= f;
    res[v][p[v]] += f;
}

void dfs(int u)
{
    isCapCityGrp[u] = true;
    for(int v = 0;v < n;v++)
    {
        if(res[u][v] > 0 && !isCapCityGrp[v])
            dfs(v);
    }
}

void solve()
{
    while(true)
    {
        resetBFS();
        f = 0;
        vis[s] = true;
        q.push(s);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            if(u == t)
            {
                augment(t, INF);
                break;
            }

            for(int v = 0;v < n;v++)
            {
                if(res[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        if(f == 0)
            break;
    }

    dfs(s);

    for(auto e : actual_edge_list)
    {
        if(isCapCityGrp[e.first] ^ isCapCityGrp[e.second])
            cout<<e.first + 1<<" "<<e.second + 1<<"\n";
    }
    cout<<"\n";
}

int main()
{
    while(cin>>n>>m)
    {
        if(!(n | m))
            break;
        reset();
        read();
        solve();
    }
    return 0;
}