#include<iostream>
#include<vector>
#include<stack>

using namespace std;

enum Vertex {UNVISITED, INSCC, GOTSCC};

int n, m, ct, scc_no;
vector<vector<int> > a;
vector<int> dfs_low, dfs_num, scc;
vector<Vertex> state;
stack<int> s;

void reset()
{
    a.clear();
    a.resize(n);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    dfs_num.clear();
    dfs_num.assign(n, -1);
    state.clear();
    state.assign(n, UNVISITED);
    scc.clear();
    scc.assign(n, -1);
    scc_no = ct = 0;
}

void read()
{
    scanf("%d %d", &n, &m);
    reset();
    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
}

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = ct ++;
    s.push(u);
    state[u] = INSCC;

    for(int v : a[u])
    {
        if(state[v] == UNVISITED)
            tarjanSCC(v);
        if(state[v] == INSCC)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]) // Root of the SCC
    {
        while(s.top() != u)
        {
            int v = s.top();
            s.pop();
            state[v] = GOTSCC;
            scc[v] = scc_no;
        }
        s.pop();
        state[u] = GOTSCC;
        scc[u] = scc_no ++;
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(dfs_num[u] == -1)
            tarjanSCC(u);
        printf("%d ", scc[u]);
    }
    printf("\n");
}

int main()
{
    read();
    solve();
    return 0;
}