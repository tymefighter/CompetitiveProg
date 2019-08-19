#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
stack<int> st;
int n, m;

void resetAll()
{
    adj.clear();
    adj.resize(n);
    visited.clear();
    visited.assign(n, false);
}

void read()
{
    int a, b;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }
}

void dfs(int u)
{
    visited[u] = true;

    for(int v : adj[u])
    {
        if(!visited[v])
            dfs(v);
    }

    st.push(u);
}

void solve()
{
    int u, ct = 0;
    for(u = 0;u < n;u++)
    {
        if(! visited[u])
            dfs(u);
    }

    while(! st.empty())
    {
        if(ct)
            cout<<" ";
        cout<<st.top()+1;
        st.pop();
        ct++;
    }
}

int main()
{
    while(cin>>n>>m)
    {
        if((n | m) == 0)
            break;
        resetAll();
        read();
        solve();
        cout<<"\n";
    }

    return 0;
}