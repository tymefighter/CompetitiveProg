#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n, m;
vector<vector<pair<int, int> > > a;
vector<int> vals, dist;
vector<bool> mark;

int cube(int x)
{
    return x * x * x;
}

void reset()
{
    a.clear();
    vals.clear();
    dist.clear();
    mark.clear();

    a.resize(n);
    vals.resize(n);
    dist.assign(n, 100000000);
    mark.assign(n, false);
}

void read()
{
    int i;
    for(i = 0;i < n;i++)
        cin>>vals[i];
    
    cin>>m;
    int x, y, w;
    for(i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        w = cube(vals[y] - vals[x]);
        a[x].push_back({y, w});
    }
}

void relax(int u, int v, int w)
{
    if(dist[u] < 100000000 && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
}

void dfs(int u)
{
    mark[u] = true;

    for(pair<int, int> v : a[u])
    {
        if(!mark[v.first])
            dfs(v.first);
    }
}

void BellmanFord(int s)
{
    if(!n)
        return;
    int i, u, v, w;
    dist[s] = 0;

    for(i = 0;i < n-1;i++)
    {
        for(u = 0;u < n;u++)
        {
            for(pair<int, int> v : a[u])
                relax(u, v.first, v.second);
        }
    }


    for(u = 0;u < n;u++)
    {
        for(pair<int, int> v : a[u])
        {
            if(dist[u] < 100000000 && dist[v.first] < 100000000 && dist[u] + v.second < dist[v.first]) // neg cycle
            {
                if(!mark[u])
                    dfs(u);
            }
        }
    }
}

void solve()
{
    int q, s;
    cin>>q;

    while(q--)
    {
        cin>>s;
        s--;
        if(s >= n || mark[s] || dist[s] < 3 || dist[s] >= 100000000)
            cout<<"?\n";
        else
            cout<<dist[s]<<"\n";
    }
}

int main()
{
    int c = 1;
    while(cin>>n)
    {
        cout<<"Set #"<<c<<"\n";
        reset();
        read();
        BellmanFord(0);
        solve();
        c++;
    }
    
    return 0;
}