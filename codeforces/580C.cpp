#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 100005;
int n, m;
vector<vector<int> > a;
int deg[MAX_SIZE], max_count[MAX_SIZE], curr_count[MAX_SIZE];
bool has_cat[MAX_SIZE];

void reset()
{
    a.resize(n);
}

void read()
{
    cin>>n>>m;
    reset();

    for(int i = 0;i < n;i++)
    {
        cin>>has_cat[i];
        deg[i] = 0;
        max_count[i] = curr_count[i] = -1;
    }

    int u, v;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v --;
        deg[u] ++;
        deg[v] ++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u, int parent)
{
    if(has_cat[u])
    {
        if(parent != -1)
            curr_count[u] = curr_count[parent] + 1;
        else
            curr_count[u] = 1;
    }
    else
        curr_count[u] = 0;
    
    max_count[u] = curr_count[u];
    if(parent != -1)
        max_count[u] = max(max_count[u], max_count[parent]);

    for(auto v : a[u])
    {
        if(curr_count[v] == -1)
            dfs(v, u);
    }
}

void solve()
{
    dfs(0, -1);
    int ans = 0;

    for(int u = 1;u < n;u++)
    {
        if(deg[u] == 1 && max_count[u] <= m)
            ans ++;
    }

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}