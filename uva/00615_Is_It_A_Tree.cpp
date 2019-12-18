#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n;
map<int, int> m;
vector<vector<int> > a;
vector<int> indeg;
vector<bool> vis;
vector<pair<int, int> > elist;

void reset()
{
    n = 0;
    a.clear();
    m.clear();
    indeg.clear();
    vis.clear();
    elist.clear();
}

bool read()
{
    int u, v;
    reset();

    while(cin>>u>>v)
    {
        if(u < 0 || v < 0)
            return false;

        if(!(u | v))
            break;

        if(m.find(u) == m.end())
            m[u] = n ++;
        if(m.find(v) == m.end())
            m[v] = n ++;
        
        elist.push_back({m[u], m[v]});
    }

    a.resize(n);
    indeg.assign(n, 0);
    vis.assign(n, false);

    for(auto e : elist)
    {
        indeg[e.second] ++;
        a[e.first].push_back(e.second);
    }

    return true;
}

bool isTree;

void dfs(int u)
{
    vis[u] = true;

    for(int v : a[u])
    {
        if(vis[v])
        {
            isTree = false;
            return;
        }
        dfs(v);
        
        if(!isTree)
            return;
    }
}

bool solve()
{
    if(n == 0)
        return true;
    int root = -1, zero_in_count = 0;

    for(int i = 0;i < n;i++)
    {
        if(indeg[i] == 0)
        {
            root = i;
            zero_in_count ++;
            if(zero_in_count == 2)
                return false;
        }
    }

    if(root == -1)
        return false;

    isTree = true;
    dfs(root);
    if(!isTree)
        return false;
    
    for(int i = 0;i < n;i++)
    {
        if(!vis[i])
            return false;
    }

    return true;
}

int main()
{
    int case_no = 1;
    while(read())
    {
        if(solve())
            printf("Case %d is a tree.\n", case_no);
        else
            printf("Case %d is not a tree.\n", case_no);
        case_no ++;
    }
    return 0;
}