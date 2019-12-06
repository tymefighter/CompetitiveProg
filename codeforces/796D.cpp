#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int n, k, d;
int dist[300005];                  // Distance Array
bool edge_used[300005];            // Edge Used Array
set<int> ps;                       // Police Stations
vector<vector<pair<int, int> > > a;
queue<int> q;

void read()
{
    cin>>n>>k>>d;
    a.resize(n);

    int u, v;
    for(int i = 0;i < k;i++)
    {
        cin>>u;
        ps.insert(u - 1);
    }

    k = ps.size();

    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u--, v--;
        a[u].push_back({v, i});
        a[v].push_back({u, i});
        
        edge_used[i] = false;
        dist[i] = -1;
    }
    dist[n - 1] = -1;
}

void solve()
{
    int u;
    for(int pStation : ps)
    {
        q.push(pStation);
        dist[pStation] = 0;
    }

    while(!q.empty())
    {
        u = q.front(), q.pop();

        if(dist[u] == d)
        {
            while(!q.empty())
                q.pop();
            break;
        }

        for(auto v : a[u])
        {
            if(dist[v.first] == -1)
            {
                dist[v.first] = dist[u] + 1;
                q.push(v.first);
                edge_used[v.second] = true;
            }
        }
    }

    cout<<k - 1<<"\n";
    for(u = 0;u < n - 1;u++)
    {
        if(!edge_used[u])
            cout<<u + 1<<" ";
    }
    cout<<"\n";
}


int main()
{
    read();
    solve();
    return 0;
}