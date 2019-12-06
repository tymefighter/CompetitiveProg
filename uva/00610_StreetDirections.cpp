#include<iostream>
#include<vector>

using namespace std;

const int N = 1005;

int n, m;
int ct, dfs_low[N], dfs_num[N];
vector<vector<int> > a;

void reset()
{
    ct = 0;
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        dfs_num[i] = -1;
}

void read()
{
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u, int parent)
{
    dfs_num[u] = dfs_low[u] = ct++;

    for(int v : a[u])
    {
        if(dfs_num[v] == -1)
        {
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if(dfs_low[v] > dfs_num[u])
            {
                cout<<u + 1<<" "<<v + 1<<"\n";
                cout<<v + 1<<" "<<u + 1<<"\n";
            }
            else
                cout<<u + 1<<" "<<v + 1<<"\n";
        }
        else if(v != parent)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            if(dfs_num[u] > dfs_num[v])
                cout<<u + 1<<" "<<v + 1<<"\n";
        }
    }
}

int main()
{
    int cno = 1;
    while(cin>>n>>m)
    {
        if(!(n | m))
            break;
        reset();
        read();
        cout<<cno++<<"\n\n";
        dfs(0, -1);
        cout<<"#\n";
    }
    return 0;
}