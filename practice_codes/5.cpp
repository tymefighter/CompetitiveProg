#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int n, m, no, ct;
stack<int> s;
vector<vector<int> > a;
vector<int> status, scc, dfs_low, dfs_num;

void reset()
{
    a.clear();
    a.resize(n);
    status.clear();
    status.assign(n, -1);
    scc.clear();
    scc.assign(n, -1);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    dfs_num.clear();
    dfs_num.assign(n, -1);
}

void read()
{
    cin>>n>>m;
    reset();
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }
}

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = ct++;
    status[u] = 0;
    s.push(u);

    for(int v : a[u])
    {
        if(status[v] == -1)
            tarjanSCC(v);

        if(status[v] == 0)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        scc[u] = no;
        int v = -1;
        while(v != u)
        {
            v = s.top(), s.pop();
            status[v] = 1;
            scc[v] = no;
        }
        no++;
    }
}

void solve()
{
    ct = 0, no = 0;

    for(int u = 0;u < n;u++)
    {
        if(status[u] == -1)
            tarjanSCC(u);
    }

    for(int u = 0;u < n;u++)
        cout<<scc[u]<<" ";
    cout<<"\n";
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
