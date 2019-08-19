#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, max_day, max_b;
vector<int> dist;
vector<vector<int> > a;
queue<int> q;

void reset()
{
    a.clear();
    dist.clear();

    a.resize(n);
}

void read()
{
    int i , j, m, k;
    for(i = 0;i < n;i++)
    {
        cin>>m;
        //cout<<m<<"==\n";
        for(j = 0;j < m;j++)
        {
            cin>>k;
            a[i].push_back(k);
        }
    }
}

void bfs(int u)
{
    dist[u] = 0;
    q.push(u);
    int val, prev;

    max_day = max_b = val = prev = 0;

    while(! q.empty())
    {
        u = q.front();
        q.pop();

        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1; 
                if(dist[v] == prev)
                    val++;
                else
                {
                    val = 1;
                    prev = dist[v];
                }

                if(val > max_b)
                {
                    max_b = val;
                    max_day = prev;
                }

                q.push(v);
            }
        }
    }
}


void solve()
{
    int t, x;
    cin>>t;
    while(t--)
    {
        dist.assign(n, -1);
        cin>>x;
        bfs(x);
        if(!max_day)
            cout<<"0\n";
        else
            cout<<max_b<<" "<<max_day<<"\n";
    }
}

int main()
{
    while(cin>>n)
    {
        reset();
        read();
        solve();
    }

    return 0;
}