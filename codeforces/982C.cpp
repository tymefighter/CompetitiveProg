#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int> > a;
vector<int> visited;

void reset()
{
    a.clear();
    a.resize(n);
    visited.clear();
    visited.assign(n, false);
}

void read()
{
    cin>>n;
    reset();

    int x, y;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

int ans;

int dfs(int u)
{
    visited[u] = true;
    int x = 1, val;

    for(int v : a[u])
    {
        if(!visited[v])
        {
            val = dfs(v);
            if(val % 2 == 0)
                ans++;
            else
                x += val;
        }
    }

    return x;
}

int main()
{
    read();

    if(n % 2)
        cout<<"-1\n";
    else
    {
        ans = 0;
        dfs(0);
        cout<<ans<<"\n";
    }
    
    return 0;
}