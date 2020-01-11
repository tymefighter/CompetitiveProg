#include<iostream>
#include<vector>

using namespace std;

const int N = 200005;
long long ans[N];       // ans[i]: the points we get if we begin at i
int n, dp[N];              // dp[i] : Number of nodes in the subtree (of the tree rooted at 0) rooted at i
vector<vector<int> > a; // The tree

void reset()
{
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        ans[i] = dp[i] = -1;
}

void read()
{
    int u, v;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

int dfs_get_subtree_size(int u)
{
    dp[u] = 1;

    for(int v : a[u])
    {
        if(dp[v] == -1)
            dp[u] += dfs_get_subtree_size(v);
    }

    return dp[u];
}

long long get_ans_0(int u, int parent)
{
    long long val = dp[u];

    for(int v : a[u])
    {
        if(v == parent)
            continue;
        val += get_ans_0(v, u);
    }

    return val;
}

void dfs(int u, long long value_above)
{
    for(int v : a[u])
    {
        if(ans[v] == -1)
        {
            ans[v] = ans[u] + dp[u] - 2 * dp[v] + value_above;
            dfs(v, value_above + dp[u] - dp[v]);
        }
    }
}

void solve()
{
    (void)dfs_get_subtree_size(0);
    ans[0] = get_ans_0(0, -1);
    
    dfs(0, 0);

    long long ans_val = 0;
    for(int i = 0;i < n;i++)
        ans_val = max(ans_val, ans[i]);

    cout<<ans_val<<"\n";
}

int main()
{
    cin>>n;
    reset();
    read();
    solve();
    return 0;
}