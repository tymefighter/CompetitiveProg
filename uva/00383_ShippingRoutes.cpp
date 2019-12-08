#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

const int N = 35;

int n, m, p;
vector<vector<int> > a;
map<string, int> code2ind;
queue<int> q;
int dist[N];

void resetDist()
{
    for(int i = 0;i < n;i++)
        dist[i] = -1;

    while(!q.empty())
        q.pop();
}

void reset()
{
    a.clear();
    a.resize(n);
    code2ind.clear();
}

void read()
{
    string u, v;
    for(int i = 0;i < n;i++)
    {
        cin>>u;
        code2ind[u] = i;
    }

    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        a[code2ind[u]].push_back(code2ind[v]);
        a[code2ind[v]].push_back(code2ind[u]);
    }
}

int bfs(int u, int dest)
{
    dist[u] = 0;
    q.push(u);

    while(!q.empty())
    {
        u = q.front(), q.pop();
        if(dest == u)
            break;

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[dest];
}

void solve(int data_set_no)
{
    printf("\nDATA SET  %d\n\n", data_set_no);

    int size_shipment, dist_val;
    string source, destination;
    for(int i = 0;i < p;i++)
    {
        resetDist();
        cin>>size_shipment>>source>>destination;
        dist_val = bfs(code2ind[source], code2ind[destination]);
        
        if(dist_val == -1)
            printf("NO SHIPMENT POSSIBLE\n");
        else
            printf("$%d\n", dist_val * size_shipment * 100);
    }
}

int main()
{
    printf("SHIPPING ROUTES OUTPUT\n");

    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n>>m>>p;
        reset();
        read();
        solve(i);
    }

    printf("\nEND OF OUTPUT\n");
}