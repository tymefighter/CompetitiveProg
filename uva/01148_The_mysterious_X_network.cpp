#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, s, t;
vector<vector<int> > a;

const int N = 100005;
queue<int> q;
int dist[N];

void reset()
{
    a.clear();
    a.resize(n);

    while(!q.empty())
        q.pop();
    
    for(int i = 0;i < n;i++)
        dist[i] = -1;
}

void read()
{
    int u, v, m;

    for(int i = 0;i < n;i++)
    {
        cin>>u>>m;
        for(int j = 0;j < m;j++)
        {
            cin>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }

    cin>>s>>t;
}

void solve()
{
    dist[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == t)
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

    cout<<s<<" "<<t<<" "<<dist[t] - 1<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n;
        reset();
        read();
        solve();
    }
    return 0;
}