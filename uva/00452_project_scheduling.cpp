#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

string s;
stringstream ss;
int dist[26], val[26];
bool visited[26];
vector<vector<int> > a;
vector<int> topo;

void reset()
{
    a.clear();
    a.resize(26);
    topo.clear();
    for(int i = 0;i < 26;i++)
    {
        dist[i] = -1;
        val[i] = 0;
        visited[i] = false;
    }
}

void read()
{
    char c;
    int ct = 0;
    
    while(getline(cin, s))
    {
        if(s == "")
            break;
        ss.clear();
        ss.str(s);
        //cout<<ss.str()<<"----\n";
        ss >> c;
        ss >> val[c - 'A'];
        ss >> s;

        //cout<<c<<" "<<val[c - 'A']<<"\n";

        if(s != ss.str())
        {
            //cout<<s<<"\n";
            for(char x : s)
            {
                //cout<<x<<" "<<(int)(x - 'A')<<"\n";
                a[x - 'A'].push_back(c - 'A');
            }
        }
    }
}

void dfs(int u)
{
    visited[u] = true;

    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }

    topo.push_back(u);
}

void t_sort()
{
    for(int u = 0;u < 26;u++)
    {
        if(!visited[u])
            dfs(u);
    }

    reverse(topo.begin(), topo.end());
}

void relax(int u, int v, int w)
{
    if(dist[u] + w > dist[v])
        dist[v] = dist[u] + w;
}

void solve()
{
    t_sort();

    for(int u : topo)
    {
        if(dist[u] == -1)
            dist[u] = val[u];

        for(int v : a[u])
            relax(u, v, val[v]);
    }

    int ans = -1;
    for(int u = 0;u < 26;u++)
        ans = max(ans, dist[u]);
    cout<<ans<<"\n";
}

int main()
{
    int t;
    getline(cin, s);
    ss.str(s);
    ss >> t;
    getline(cin, s);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        reset();
        read();
        solve();
    }
    return 0;
}