#include<iostream>
#include<vector>

using namespace std;

int n, q;
vector<vector<int> > a;
vector<bool> visited;
vector<int> deg;
// val[u]: number of b at vert u
// now[u]: how many b would be added to vert u now
vector<long long int> val, now;


void reset()
{
    a.clear();
    a.resize(n);
    
    val.clear();
    val.resize(n);

    now.clear();
    now.resize(n);

    deg.clear();
    deg.assign(n, 0);

    visited.clear();
}

void read()
{
    cin>>n>>q;
    reset();

    int u, v;

    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
        a[v].push_back(u);

        deg[u] ++;
        deg[v] ++;
    }

    for(int i = 0;i < n;i++)
        cin>>val[i];
}

void dfs(int u)
{
    visited[u] = true;

    for(int v : a[u])
    {
        if(!visited[v])
        {
            now[v] += val[u];
            dfs(v);
        }
    }
}

void update()
{
    for(int u = 0;u < n;u++)
    {
        if(u != 0 && deg[u] == 1)
            val[u] += now[u];
        else
            val[u] = now[u];
    }
}

void solve()
{
    char c;
    int v;
    long long k;

    while(q--)
    {
        cin>>c;

        now.assign(n, 0);
        visited.assign(n, false);
        dfs(0);
        update();

        if(c == '+')
        {
            cin>>v>>k;
            v --;
            val[v] += k;
        }
        else if(c == '?')
        {
            cin>>v;
            v --;
            cout<<val[v]<<"\n";
        }
    }
}

int main()
{
    read();
    solve();
    return 0;
}