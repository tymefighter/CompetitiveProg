#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n, m, cno, ct;
stack<int> st;
vector<vector<int> > a;
vector<int> dfs_num, dfs_low, state, comp;
// cno: component number, ct: counter value
// st: stack to store the vertices
// state - 0: unvisited, 1: visited, 2: explored

void reset()
{
    a.clear();
    a.resize(n);

    dfs_num.clear();
    dfs_num.assign(n, -1);

    dfs_low.clear();
    dfs_low.assign(n, -1);

    state.clear();
    state.assign(n, 0);

    comp.clear();
    comp.assign(n, -1);

    cno = ct = 0;
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
    st.push(u);
    dfs_low[u] = dfs_num[u] = ct ++;
    state[u] = 1;

    for(int v : a[u])
    {
        if(state[v] == 0)
            tarjanSCC(v);
        
        if(state[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        int v = -1;
        while(v != u)
        {
            v = st.top(), st.pop();
            state[v] = 2;
            comp[v] = cno;
        }
        cno ++;
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(state[u] == 0)
            tarjanSCC(u);
        
        cout<<comp[u]<<" ";
    }
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