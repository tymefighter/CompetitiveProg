#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > adj;
vector<int> dfs_low, dfs_num;
vector<bool> in_scc;
stack<int> st;
int n, m, ct;
bool checked;

void reset()
{
    adj.clear();
    dfs_low.clear();
    dfs_num.clear();
    in_scc.clear();    

    adj.resize(n);
    dfs_low.assign(n, -1);
    dfs_num.assign(n, -1);
    in_scc.assign(n, false);
    ct = 0;
    checked = false;

    while(!st.empty())
        st.pop();

}

void read()
{
    int a, b, tp;

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>tp;
        a--, b--;
        adj[a].push_back(b);
        if(tp == 2)
            adj[b].push_back(a);
    }
}

bool tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = ct++;
    st.push(u);
    in_scc[u] = true;
    bool val = false;

    for(int v : adj[u])
    {
        if(dfs_num[v] == -1)
            val |= tarjan(v);
        
        if(in_scc[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u] && !checked)
    {
        checked = true;
        if(st.size() != n)
            return false;

        int v;
        while(!st.empty())
        {
            v = st.top();
            st.pop();
        }

        if(v == u)
            return true;
        else
            return false;
    }

    return val;
}

int main()
{

    while(cin>>n>>m)
    {
        if((n | m) == 0)
            break;

        reset();
        read();
        if(tarjan(0))
            cout<<1;
        else
            cout<<0;
        cout<<"\n";
    }
    return 0;
}