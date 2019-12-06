#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<int> state;  // 0: unvisited, 1: visited, 2: explored
set<pair<int, int> > tree, for_cross, back;

void reset()
{
    a.clear();
    a.resize(n);
    state.clear();
    state.assign(n, 0);

    tree.clear();
    for_cross.clear();
    back.clear();
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

void dfs(int u)
{
    state[u] = 1;                   // visited (just entered)

    for(int v : a[u])
    {
        if(state[v] == 0)
        {
            tree.insert({u, v});
            dfs(v);
        }
        else if(state[v] == 1)
            back.insert({u, v});
        else
            for_cross.insert({u, v});
    }

    state[u] = 2;                   // explored (all verts reachable from u have been seen)
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(state[u] == 0)
            dfs(u);
    }

    printf("Tree: -\n");
    for(auto x : tree)
        printf("(%d, %d)\n", x.first, x.second);
    printf("For/Cross: -\n");
    for(auto x : for_cross)
        printf("(%d, %d)\n", x.first, x.second);
    printf("back: -\n");
    for(auto x : back)
        printf("(%d, %d)\n", x.first, x.second);
}

int main()
{
    read();
    solve();
    return 0;
}