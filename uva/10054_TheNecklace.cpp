#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<set>
#include<cstdio>

using namespace std;

set<int> s;
list<int> tour;
vector<int> indeg;
vector<bool> visited;
vector<vector<pair<int, bool> > >a;
int n;

void reset()
{
    a.clear();
    a.resize(50);
    tour.clear();
    indeg.clear();
    indeg.assign(50, 0);
    s.clear();
    visited.clear();
    visited.assign(50, false);
}

void read()
{
    cin>>n;

    reset();

    int x, y;
    for(int i = 0;i < n;i++)
    {
        cin>>x>>y;
        x--, y--;
        indeg[x]++;
        indeg[y]++;
        a[x].push_back({y, true});
        a[y].push_back({x, true});
        s.insert(x);
        s.insert(y);
    }
}

void EulerTour(list<int>::iterator i, int u)
{
    int j, k;
    for(j = 0;j < a[u].size();j++)
    {
        pair<int, bool> v = a[u][j];
        if(!v.second)
            continue;
        
        a[u][j].second = false;
        for(k = 0;k < a[v.first].size();k++)
        {
            pair<int, bool> x = a[v.first][k];
            if(x.first == u && x.second)
            {
                a[v.first][k].second = false;
                break;
            }
        }

        EulerTour(tour.insert(i, u), v.first);
    }
}

void dfs(int u)
{
    visited[u] = true;

    for(pair<int, bool> v : a[u])
    {
        if(!visited[v.first])
            dfs(v.first);
    }
}

bool solve()
{
    int u = *s.begin();
    dfs(u);
    for(int x : s)
    {
        if(!visited[x])
            return false;
    }

    for(int i = 0;i < 50;i++)
    {
        if(indeg[i] % 2)
            return false;
    }

    EulerTour(tour.begin(), u);
    list<int> :: iterator j;
    for(list<int> :: iterator i = tour.begin();i != tour.end();i++)
    {
        j = i;
        j++;
        if(j == tour.end())
            j = tour.begin();
        cout<<(*i) + 1<<" "<<(*j) + 1<<"\n";
    }
    
    return true;
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        if(i != 1)
            cout<<"\n";
        printf("Case #%d\n", i);
        read();
        if(!solve())
            cout<<"some beads may be lost\n";
    }
    return 0;
}