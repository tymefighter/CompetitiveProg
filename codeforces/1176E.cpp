#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<int> dist;
queue<int> q;
int no, ne; // num_odd, num_even - distances

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

    int x, y;
    for(int i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void bfs()
{
    dist[0] = 0;
    q.push(0);
    int u;
    no = ne = 0;
    while(!q.empty())
    {
        u = q.front(), q.pop();
        if(dist[u] % 2)
            no++;
        else
            ne++;

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if(no > ne)
    {
        cout<<ne<<"\n";
        for(u = 0;u < n;u++)
        {
            if(dist[u] % 2 == 0)
                cout<<u+1<<" ";
        }
    }
    else
    {
        cout<<no<<"\n";
        for(u = 0;u < n;u++)
        {
            if(dist[u] % 2)
                cout<<u+1<<" ";
        }
    }
    cout<<"\n";
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
    
}