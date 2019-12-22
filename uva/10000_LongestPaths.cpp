#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 105;
int s, n, dp[N];
vector<vector<int> > a;
vector<int> topo;
bool vis[N]; 

void reset()
{
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
    {
        vis[i] = false;
        dp[i] = -1;
    }

    topo.clear();
}

void read()
{
    int u, v;

    cin>>s;
    s --;
    while(cin>>u>>v)
    {
        if(!(u | v))
            break;
        u --, v --;
        a[u].push_back(v);
    }
}

void dfs_t_sort(int u)
{
    vis[u] = true;
    for(int v : a[u])
    {
        if(!vis[v])
            dfs_t_sort(v);
    }

    topo.push_back(u);
}

void solve(int cno)
{
    for(int u = 0;u < n;u++)
    {
        if(!vis[u])
            dfs_t_sort(u);
    }

    reverse(topo.begin(), topo.end());

    dp[s] = 0;
    int ans_val = 0, ans = s;
    for(int u : topo)
    {
        if(dp[u] == -1)
            continue;
        if(ans_val <= dp[u])
        {
            if(ans_val < dp[u] || u < ans)
            {
                ans_val = dp[u];
                ans = u;
            }
        }

        for(int v : a[u])
            dp[v] = max(dp[v], dp[u] + 1);
    }

    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", cno, s + 1, ans_val, ans + 1);
}

int main()
{
    int cno = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        reset();
        read();
        solve(cno);
        cno ++;
        cout<<"\n";
    }
    return 0;
}