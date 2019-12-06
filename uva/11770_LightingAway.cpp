#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 10005;

int n, m;
vector<vector<int> > a;
vector<int> topo;
bool vis[N];

void resetVis()
{
    for(int i = 0;i < n;i++)
        vis[i] = false;
}

void reset()
{
    a.clear();
    a.resize(n);
    topo.clear();
}

void read()
{
    cin>>n>>m;
    reset();

    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
    }
}

void dfs(int u, const int &doing_t_sort)
{
    vis[u] = true;

    for(int v : a[u])
    {
        if(!vis[v])
            dfs(v, doing_t_sort);
    }
    
    if(doing_t_sort)
        topo.push_back(u);
}

void solve(int cno)
{
    resetVis();
    for(int i = 0;i < n;i++)
    {
        if(!vis[i])
            dfs(i, true);
    }
    reverse(topo.begin(), topo.end());

    int ans = 0;
    resetVis();
    for(int u : topo)
    {
        if(!vis[u])
        {
            dfs(u, false);
            ans ++;
        }
    }
    printf("Case %d: %d\n", cno, ans);
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        solve(i);
    }
    return 0;
}