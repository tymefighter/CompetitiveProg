#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, dist[100005], pre[100005];
vector<vector<int> > a;
queue<int> q;

void reset()
{
    a.clear();
    a.resize(n);
    while(!q.empty())
        q.pop();
}

void read()
{
    cin>>n;
    reset();

    int i, j, m, v;
    for(i = 0;i < n - 1;i++)
    {
        dist[i] = -1;
        pre[i] = -1;
        cin>>m;
        for(j = 0;j < m;j++)
        {
            cin>>v;
            v --;
            a[i].push_back(v);
        }

        sort(a[i].begin(), a[i].end());
    }
    dist[n - 1] = -1;
    pre[n - 1] = -1;
}

void printPath(int v)
{
    if(v == -1)
        return;
    
    printPath(pre[v]);
    cout<<v + 1<<" ";
}

void bfs()
{
    dist[0] = 0;
    q.push(0);

    int u, dval;

    while(!q.empty())
    {
        u = q.front(), q.pop();
        dval = dist[u];

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dval + 1;
                pre[v] = u;
                if(v == n - 1)
                {
                    cout<<dist[v]<<"\n";
                    printPath(pre[n - 1]);
                    cout<<"\n\n";
                    return;
                }
                q.push(v);
            }
        }
    }

    cout<<"-1\n\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        bfs();
    }
    return 0;
}