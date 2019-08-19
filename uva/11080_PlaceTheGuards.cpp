#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int> >adj;
vector<int> color;

void resetAll()
{
    color.clear();
    color.assign(n, -1);
    adj.clear();
    adj.resize(n);
}

void read()
{
    int a, b;
    cin>>n>>m;

    resetAll();

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int bfs(int u)
{
    int zero, one;
    zero = one = 0;
    queue<int> q;

    color[u] = 0;
    q.push(u);

    while(! q.empty())
    {
        u = q.front();
        q.pop();

        if(color[u] == 0)
            zero++;
        else
            one++;

        for(int v : adj[u])
        {
            if(color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u])
                return -1;
        }
    }

    if(one == 0) // If only one node is present, then return 1
        return zero;
    else
        return min(zero, one); // If we can colour with both, return the color count which is lesser
}

int solve()
{
    int ans = 0, val;
    for(int u = 0;u < n;u++)
    {
        if(color[u] == -1)
        {
            val = bfs(u);
            if(val < 0)
                return val;
            ans += val;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        cout<<solve()<<'\n';
    }

    return 0;
}