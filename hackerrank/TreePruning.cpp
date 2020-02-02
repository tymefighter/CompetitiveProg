#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int N = 100005, K = 205;
int n, k;
long long w[N], dp[N][K], subtree_size[N];
vector<vector<int> > a;
vector<int> d; // dfs order of vertices

void read()
{
    cin>>n>>k;
    for(int i = 0;i < n;i++)
        cin>>w[i];

    a.clear();
    a.resize(n);
    for(int i = 0;i < n - 1;i++)
    {
        int u, v;
        cin>>u>>v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u, int par)
{
    d.push_back(u);
    subtree_size[u] = 1;
    for(int v : a[u])
    {
        if(v != par)
        {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

void solve()
{
    assert(d.size() == n);
    for(int j = 0;j <= k;j++)
        dp[n][j] = 0;
    
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = 0;j <= k;j++)
        {
            dp[i][j] = dp[i + 1][j] + w[d[i]];
            if(j > 0)
                dp[i][j] = max(dp[i][j], dp[i + subtree_size[d[i]]][j - 1]);
        }
    }

    cout<<dp[0][k]<<"\n";
}


int main()
{
    read();
    d.clear();
    dfs(0, -1);
    solve();
    return 0;
}