#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
queue<int> q;
vector<vector<int> > a;
vector<int> topo;
int state[1000005], indeg[1000005];

void reset()
{
    topo.clear();
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
    {
        indeg[i] = 0;
        state[i] = 0;
    }
}

void read()
{
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
        indeg[v] ++;
    }
}

bool checkCycle(int u)
{
    state[u] = 1;           // visited

    for(int v : a[u])
    {
        if(state[v] == 1)   // visited to visited edge, hence a back edge -> cycle
            return true;
        
        if(state[v] == 0)   // If unvisited, visit it
        {
            if(checkCycle(v))
                return true;
        }
    }
    state[u] = 2;           // explored
    return false;
}

void KahnAlgo()
{
    for(int i = 0;i < n;i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for(int v : a[u])
        {
            indeg[v] --;
            if(indeg[v] == 0)
                q.push(v);
        }
    }
}

void solve()
{
    for(int i = 0;i < n;i++)
    {
        if(state[i] == 0)
        {
            if(checkCycle(i))
            {
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }

    KahnAlgo();
    for(int x : topo)
        cout<<x + 1<<"\n";
}

int main()
{
    while(cin>>n>>m)
    {
        reset();
        read();
        solve();
    }
    return 0;
}