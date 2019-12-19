#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1005;
int n, m, dist[N];
vector<vector<int> > a;

void reset()
{
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        dist[i] = -1;
}

void read()
{
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

queue<int> q;

void solve()
{
    dist[0] = 0;
    q.push(0);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1;i < n;i++)
        cout<<dist[i]<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n>>m;
        reset();
        read();
        solve();
    }
    return 0;
}