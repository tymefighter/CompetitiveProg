#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int n, s, t;

class Triple
{
    public:
    int v, ts, tf;
    
    Triple(int vert, int time_start, int time_end)
    {
        v = vert, ts = time_start, tf = time_end;
    }
};

vector<vector<Triple> > a;
deque<pair<int, int> > dq;

map<string, int> m;
vector<pair<int, Triple> > elist;

int dist[105][25];

void reset()
{
    a.clear();
    a.resize(n);

    while(!dq.empty())
        dq.pop_front();

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 1;j <= 24;j++)
            dist[i][j] = -1;
    }
}

int returnInterval(int t)
{
    if(1 <= t && t <= 6)
        return 2;
    if(18 <= t && t <= 24)
        return 1;
    
    return -1;
}

void read()
{
    m.clear();
    elist.clear();

    n = 0;
    string u, v;
    int num_edges, ts, tf;
    cin>>num_edges;
    for(int i = 0;i < num_edges;i++)
    {
        cin>>u>>v>>ts>>tf;

        if(ts == 0)
            ts = 24;
        else if(ts > 24)
        {
            ts = ts % 25;
            ts ++;
        }

        tf += ts;
        if(tf >= 25)
            tf -= 24;

        if(m.find(u) == m.end())
            m[u] = n ++;
        if(m.find(v) == m.end())
            m[v] = n ++;
        
        if(returnInterval(ts) == -1
            || returnInterval(tf) == -1)
            continue;

        if((returnInterval(ts) == 1 && returnInterval(tf) == 2)
            || (returnInterval(ts) == returnInterval(tf) && tf > ts))
        {
            elist.push_back({m[u], Triple(m[v], ts, tf)});
        }
    }

    reset();
    for(auto e : elist)
        a[e.first].push_back(e.second);
}

void solve()
{
    string uu, vv;
    cin>>uu>>vv;
    
    if(uu == vv)
    {
        printf("Vladimir needs 0 litre(s) of blood.\n");
        return;
    }
    
    if(m.find(uu) == m.end()
        || m.find(vv) == m.end())
    {
        printf("There is no route Vladimir can take.\n");
        return;
    }


    s = m[uu];
    t = m[vv];
    for(Triple v : a[s])
    {
        dist[s][v.ts] = 0;
        dq.push_back({s, v.ts});
    }

    while(!dq.empty())
    {
        pair<int, int> u = dq.front();
        dq.pop_front();

        if(u.first == t)
        {
            printf("Vladimir needs %d litre(s) of blood.\n", dist[u.first][u.second]);
            return;
        }

        for(Triple v : a[u.first])
        {
            if((u.second <= v.ts && v.ts < 12) || (12 < u.second && u.second <= v.ts)
                || (12 < u.second && v.ts < 12))
            {
                if(dist[v.v][v.tf] == -1
                    || dist[u.first][u.second] < dist[v.v][v.tf])
                {
                    dist[v.v][v.tf] = dist[u.first][u.second];
                    dq.push_front({v.v, v.tf});
                }
            }   
            else if(dist[v.v][v.tf] == -1)
            {
                dist[v.v][v.tf] = dist[u.first][u.second] + 1;
                dq.push_back({v.v, v.tf});
            }
        }
    }

    printf("There is no route Vladimir can take.\n");
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Test Case %d.\n", i);
        solve();
    }
    return 0;
}