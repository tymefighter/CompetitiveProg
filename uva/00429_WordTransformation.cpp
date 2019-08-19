#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

int n;
stringstream ss;
map<string, int> m;
vector<int> dist;
vector<string> re;
vector<vector<int> > adj;
queue<int> q;
string a, b;

void clearAll()
{
    m.clear();
    re.clear();
    dist.clear();
    adj.clear();
    ss.str("");
    ss.clear();
}

bool one_diff(int i, int j)
{
    int num_diff, min_size;

    min_size = min(re[i].size(), re[j].size());
    num_diff = abs((int)(re[i].size() - re[j].size()));
    
    if(num_diff > 1)
        return false;
    
    for(int k = 0;k < min_size;k++)
    {
        if(re[i][k] != re[j][k])
            num_diff++;
    }

    return num_diff <= 1;
}

void read()
{

    while(getline(cin, a))
    {
        if(a[0] == '*')
            break;
        m[a] = re.size();
        re.push_back(a);
    }

    n = re.size();
    adj.resize(n);

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < i;j++)
        {
            if(one_diff(i, j))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

int bfs(int st, int end)
{
    dist[st] = 0;
    q.push(st);
    int u;

    while(! q.empty())
    {
        u = q.front();
        q.pop();
        

        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

    }

    return dist[end];
}

void solve()
{
    while(getline(cin, a))
    {
        ss.clear();
        if(a[0] < 'a' || a[0] > 'z')
            break;
        ss.str(a);
        a = b = "";
        ss >> a;
        ss >> b;
        dist.assign(n, -1);
        cout<<a<<" "<<b<<" "<<bfs(m[a], m[b])<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    getline(cin, a);
    getline(cin, a);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        clearAll();
        read();
        solve();
    }
    return 0;
}