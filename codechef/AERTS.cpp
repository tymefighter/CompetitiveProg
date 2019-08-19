#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int n, m, ct, sn;
vector<vector<int> > a;
int dfs_num[1005], dfs_low[1005], b[1005], scc[1005];
long long int vals[1005];
bool in_scc[1005], visited[1005];
stack<int> s;

void reset()
{
    sn = ct = 0;
    a.clear();
    a.resize(n);
}

void read()
{
    cin>>n>>m;
    reset();

    for(int i = 0;i < n;i++)
    {
        cin>>b[i];
        in_scc[i] = false;
        visited[i] = false;
        scc[i] = -1;
        vals[i] = 0;
    }

    int st, en;
    for(int i = 0;i < m;i++)
    {
        cin>>st>>en;
        st--, en--;
        a[st].push_back(en);
    }
}

void tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = ct ++;
    visited[u] = true;
    in_scc[u] = true;
    s.push(u);
    

    for(int v : a[u])
    {
        if(!visited[v])
        {
            tarjan(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(visited[v] && in_scc[v])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
    }

    if(dfs_low[u] == dfs_num[u])
    {
        int v = s.top();
        s.pop();
        while(v != u)
        {
            in_scc[v] = false;
            scc[v] = sn;
            v = s.top();
            s.pop();
        }
        in_scc[u] = false;
        scc[u] = sn++;
    }
}

void solve()
{
    long long int ans = 0;
    
    for(int u = 0;u < n;u++)
    {
        if(scc[u] == -1)
            tarjan(u);
        //cout<<u+1<<" "<<scc[u]<<"\n";
        vals[scc[u]] += (b[u] * 1ll);
    }

    sort(vals, vals + sn);

    for(int i = 0;i < sn;i++)
    {
        //cout<<i + 1<<" "<<vals[i]<<"--\n";
        ans += vals[i] * ((i + 1) * 1ll);
    }
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}