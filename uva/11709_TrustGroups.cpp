#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

const int N = 1005;

string str;
stringstream ss;

int n, m;
map<string, int> per2ind;
vector<vector<int> > a;

// state[i]: 0 if unvisited, 1 if visited, 2 if explored
int ct, numSCC, dfs_low[N], dfs_num[N], state[N];
stack<int> s;

void reset()
{
    per2ind.clear();
    
    a.clear();
    a.resize(n);

    ct = 0;
    numSCC = 0;
    for(int i = 0;i < n;i++)
        state[i] = 0;
}

void read()
{
    for(int i = 0;i < n;i++)
    {
        getline(cin, str);
        per2ind[str] = i;
    }
    
    string u, v;
    for(int i = 0;i < m;i++)
    {
        getline(cin, u);
        getline(cin, v);

        a[per2ind[u]].push_back(per2ind[v]);
    }
}

void dfs(int u)
{
    state[u] = 1;
    s.push(u);
    dfs_low[u] = dfs_num[u] = ct ++;

    for(int v : a[u])
    {
        if(state[v] == 0)
            dfs(v);
        if(state[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        int v = -1;
        numSCC ++;
        while(v != u)
        {
            v = s.top();
            s.pop();
            state[v] = 2;
        }
    }
}

void solve()
{
    for(int i = 0;i < n;i++)
    {
        if(state[i] == 0)
            dfs(i);
    }

    cout<<numSCC<<"\n";
}

int main()
{
    while(getline(cin, str))
    {
        ss.clear();
        ss.str(str);
        ss >> n >> m;
        if(!(n | m))
            break;
        reset();
        read();
        solve();
    }
    return 0;
}