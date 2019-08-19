#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<cstdio>

using namespace std;

int n, m, ct;

vector<vector<int> > adj;
vector<int> dfs_num, dfs_low;
vector<bool> in_scc;
vector<string> remap;
map<string, int> mp;
stack<int> st;


void reset()
{
    adj.clear();
    dfs_low.clear();
    dfs_num.clear();
    in_scc.clear();
    remap.clear();
    mp.clear();

    adj.resize(n);
    dfs_low.assign(n, -1);
    dfs_num.assign(n, -1);
    in_scc.assign(n, false);

    ct = 0;
}

void read()
{
    string a, b;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b;

        if(mp.find(a) == mp.end())
        {
            mp[a] = remap.size();
            remap.push_back(a);
        }
        if(mp.find(b) == mp.end())
        {
            mp[b] = remap.size();
            remap.push_back(b);
        }

        //cout<<a<<" "<<mp[a]<<" "<<b<<" "<<mp[b]<<"\n";
        adj[mp[a]].push_back(mp[b]);
    }
}

void tarjan(int x)
{

    in_scc[x] = true;
    dfs_low[x] = dfs_num[x] = ct++;
    st.push(x);


    for(int v : adj[x])
    {
        if(dfs_num[v] == -1)
            tarjan(v);

        if(in_scc[v])
            dfs_low[x] = min(dfs_low[x], dfs_low[v]);
    }

    if(dfs_low[x] == dfs_num[x])
    {
        int v = st.top();
        st.pop();

        while(v != x)
        {
            in_scc[v] = false;
            cout<<remap[v]<<", ";
            v = st.top();
            st.pop();
        }
        in_scc[v] = false;
        cout<<remap[v]<<"\n";
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(dfs_num[u] == -1)
            tarjan(u);
    }
}

int main()
{
    int dset = 1;
    while(cin>>n>>m)
    {
        if((n | m) == 0)
            break;
        if(dset != 1)
            cout<<"\n";
        printf("Calling circles for data set %d:\n",dset);
        if(!m)
            continue;
        reset();
        read();
        solve();
        dset++;
    }

    return 0;
}