#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > adj;
vector<int> dfs_num, dfs_low, comp, comp_in_edge;
vector<bool> in_scc;
stack<int> st;
int n, m, ct, comp_no;

void reset()
{
    adj.clear();
    dfs_num.clear();
    dfs_low.clear();
    in_scc.clear();
    comp.clear();
    comp_in_edge.clear();

    adj.resize(n);
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    in_scc.assign(n, false);
    comp.assign(n, -1); // no components have been assigned
    comp_in_edge.assign(n, true); // assume that initially all comp have inedges
    ct = 0;
    comp_no = 0;
}

void read()
{
    int a, b;
    cin>>n>>m;

    reset();

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
    }
}

void tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = ct++;
    in_scc[u] = true;
    st.push(u);

    for(int v : adj[u])
    {
        if(dfs_low[v] == -1)
            tarjan(v);

        if(in_scc[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        int v = st.top();
        st.pop();

        while(v != u)
        {
            in_scc[v] = false;
            comp[v] = comp_no;
            v = st.top();
            st.pop();   
        }
        in_scc[u] = false; // never forget this !!!!!!!
        comp[u] = comp_no;
        comp_in_edge[comp_no] = false;
        comp_no++;
    }
}

void solve()
{
    int u;
    for(u = 0;u < n;u++)
    {
        if(dfs_low[u] == -1)
            tarjan(u);
    }


    for(u = 0;u < n;u++)
    {
        for(int v : adj[u])
        {
            if(comp[u] != comp[v] && comp_in_edge[comp[v]] == false)
            {
                comp_no--;
                comp_in_edge[comp[v]] = true;
            }
        }
    }

    return;
}



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        solve();
        cout<<comp_no<<"\n";
    }

    return 0;
}