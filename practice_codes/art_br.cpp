#include<iostream>
#include<vector>

using namespace std;

int n, m, ct;
vector<vector<int> > a;
vector<int> dfs_low, dfs_num;
vector<bool> is_art;

void reset()
{
    ct = 0;
    a.clear();
    a.resize(n);
    is_art.clear();
    is_art.assign(n, false);
    dfs_low.clear();
    dfs_low.assign(n, -1);
    dfs_num.clear();
    dfs_num.assign(n, -1);
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
        a[v].push_back(u);
    }
}

int root, num_ch;

void articulationPtAndBridges(int u, int parent)
{
    dfs_low[u] = dfs_num[u] = ct ++;

    for(int v : a[u])
    {
        if(dfs_num[v] == -1) // point was not visited earlier
        {
            articulationPtAndBridges(v, u); // visit the point and computing the values for v

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if(u == root)
                num_ch ++;
            else if(dfs_low[v] >= dfs_num[u])
                is_art[u] = true;
            
            if(dfs_low[v] > dfs_num[u])
                printf("(%d, %d)\n", u, v);
        }
        else if(v != parent)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void solve()
{
    for(int u = 0;u < n;u++)
    {
        if(dfs_num[u] == -1)
        {
            root = u;
            num_ch = 0;
            articulationPtAndBridges(u, -1);
            if(num_ch > 1)
                is_art[u] = true;
        }
    }
    for(int u = 0;u < n;u++)
    {
        if(is_art[u])
            printf("%d\n", u);
    }
}

int main()
{
    read();
    solve();
    return 0;
}