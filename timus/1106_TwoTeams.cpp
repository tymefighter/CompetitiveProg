#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 105;

int n, group[MAX_SIZE];
vector<vector<int> > a;

void reset()
{
    a.resize(n);
    for(int i = 0;i < n;i++)
        group[i] = -1;
}

void read()
{
    cin>>n;
    reset();

    int u;
    for(int i = 0;i < n;i++)
    {
        while(true)
        {
            cin>>u;
            if(!u)
                break;
            u --;
            a[i].push_back(u);
        }
    }
}

void dfs(int u)
{
    for(int v : a[u])
    {
        if(group[v] == -1)
        {
            group[v] = 1 - group[u];
            dfs(v);
        }
    }
}

void solve()
{
    for(int i = 0;i < n;i++)
    {
        if(group[i] == -1)
        {
            group[i] = 0;
            dfs(i);
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++)
        ans += group[i];

    cout<<ans<<"\n";
    for(int i = 0;i < n;i++)
    {
        if(group[i])
            cout<<i + 1<<" ";
    }
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}