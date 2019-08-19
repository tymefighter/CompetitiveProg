#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<bool> visited;

void reset()
{
    a.clear();
    a.resize(n);
    visited.clear();
    visited.assign(n, false);
}

void read()
{
    int x, y;
    cin>>n>>m;
    reset();
    for(int i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u)
{
    visited[u] = true;

    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

bool solve()
{
    if(m != n - 1)
        return false;

    dfs(0);
    
    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            return false;
    }
    return true;
}

int main()
{
    read();
    if(solve())
        cout<<"yes\n";
    else
        cout<<"no\n";
    return 0;
}