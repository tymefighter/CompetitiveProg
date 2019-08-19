#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s;
vector<vector<int> >a;
vector<int> dist;
queue<int> q;

void reset()
{
    a.clear();
    dist.clear();
    a.resize(n);
    dist.assign(n, -1);
}

void read()
{
    cin>>n>>m;
    reset();
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin>>s;
    s--;
}

void solve()
{
    int u;
    dist[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 6;
                q.push(v);
            }
        }
    }

    for(u = 0;u < n;u++)
    {
        if(u == s)
            continue;
        cout<<dist[u]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        read();
        solve();
    }
    return 0;
}