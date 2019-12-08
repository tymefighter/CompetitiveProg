#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

const int N = 35;

map<int, int> m;
int n, dist[N];
vector<vector<int> > a;
vector<pair<int, int> > elist, query;
queue<int> q;

void reset()
{
    n = 0;
    m.clear();
    a.clear();
    elist.clear();
    query.clear();
}

void read(int num_edges)
{
    int u, v;

    for(int i = 0;i < num_edges;i++)
    {
        cin>>u>>v;
        if(m.find(u) == m.end())
            m[u] = n ++;
        if(m.find(v) == m.end())
            m[v] = n ++;

        elist.push_back({m[u], m[v]});
    }

    int x, ttl;
    while(cin>>x>>ttl)
    {
        if(!(x | ttl))
            break;
        if(m.find(x) == m.end())
            m[x] = n ++;
        
        query.push_back({x, ttl});
    }


    a.resize(n);

    for(auto e : elist)
    {
        a[e.first].push_back(e.second);
        a[e.second].push_back(e.first);
    }
}

void bfs(int u)
{
    q.push(u);
    dist[u] = 0;

    while(!q.empty())
    {
        u = q.front(), q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int case_no;

void solve()
{
    int x, u, ttl;
    for(auto qry : query)
    {
        x = qry.first;
        u = m[x];
        ttl = qry.second;

        for(int j = 0;j < n;j++)
            dist[j] = -1;

        bfs(u);
        int val = 0;
        for(int j = 0;j < n;j++)
        {
            if(dist[j] == -1 || dist[j] > ttl)
                val ++;
        }

        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", case_no, val, x, ttl);
        case_no ++;
    }
}

int main()
{
    int num_edges;
    case_no = 1;
    while(cin>>num_edges)
    {
        if(!num_edges)
            break;
        reset();
        read(num_edges);
        solve();
    }
    return 0;
}