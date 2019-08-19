#include<iostream>
#include<vector>

using namespace std;

int n, rm_n;
vector<vector<int> > adj;
vector<bool> visited, not_reach;

void reset()
{
    adj.clear();
    visited.clear();
    not_reach.clear();
}

void read()
{
    cin>>n;
    adj.resize(n);
    visited.assign(n, false);
    not_reach.assign(n, false);

    int i, j, x;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>x;
            if(x)
                adj[i].push_back(j);
        }
    }
}

void dfs(int u)
{
    if(u == rm_n)
        return;

    visited[u] = true;
    for(int x : adj[u])
    {
        if(!visited[x])
            dfs(x);
    }
}

void print_line()
{
    cout<<'+';
    for(int i = 0;i < 2 * n - 1;i++)
        cout<<"-";
    cout<<"+\n";
}

void reset_vis()
{
    for(int i = 0;i < visited.size();i++)
        visited[i] = false;
}

void solve()
{
    int u;
    rm_n = -1;
    dfs(0);

    for(u = 0;u < n;u++)
    {
        if(!visited[u])
            not_reach[u] = true;
    }

    print_line();
    for(rm_n = 0;rm_n < n;rm_n++)
    {
        cout<<'|';
        for(u = 0;u < n;u++)
        {
            if(not_reach[u])
            {
                cout<<"N|";
                continue;
            }

            reset_vis();
            dfs(0);
            if(visited[u])
                cout<<"N|";
            else
                cout<<"Y|";
        }

        cout<<"\n";
        print_line();
    }

}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        printf("Case %d:\n", i);
        reset();
        read();
        solve();
    }
    return 0;
}