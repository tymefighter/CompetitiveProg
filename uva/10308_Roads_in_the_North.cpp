#include<iostream>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

vector<pair<pair<int, int> , int> > elist;
map<int, int> m;

int n;
stringstream ss;
string s;
vector<vector<pair<int, int> > > a;

void reset()
{
    a.clear();
    a.resize(n);
}

void read()
{
    int u, v, w;

    m.clear();
    elist.clear();
    n = 0;
    while(s != "")
    {
        ss.clear();
        ss.str(s);

        ss >> u >> v >> w;
        if(m.find(u) == m.end())
            m[u] = n ++;
        if(m.find(v) == m.end())
            m[v] = n ++;

        elist.push_back({{m[u], m[v]}, w});
        getline(cin, s);
    }

    reset();
    for(auto e : elist)
    {
        a[e.first.first].push_back({e.first.second, e.second});
        a[e.first.second].push_back({e.first.first, e.second});
    }
}

int dist[100005];

void resetDist()
{
    for(int i = 0;i < n;i++)
        dist[i] = -1;
}

void dfs(int u)
{
    for(auto v : a[u])
    {
        if(dist[v.first] == -1)
        {
            dist[v.first] = dist[u] + v.second;
            dfs(v.first);
        }
    }
}

void getDiameter()
{
    resetDist();
    dist[0] = 0;
    dfs(0);

    int s = 0;
    for(int i = 1;i < n;i++)
    {
        if(dist[i] > dist[s])
            s = i;
    }

    resetDist();
    dist[s] = 0;
    dfs(s);

    int ans = -1;
    for(int i = 0;i < n;i++)
        ans = max(ans, dist[i]);
    
    cout<<ans<<"\n";
}

int main()
{
    while(getline(cin, s))
    {
        read();
        getDiameter();
    }
    return 0;
}