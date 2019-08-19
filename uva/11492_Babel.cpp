#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<map>

using namespace std;

int M, s, e, n;
vector<vector<pair<int, pair<int, int> > > > a;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
int dist[4004][26];
map<string, int> m;
string st, st_a, st_b;

void reset()
{
    a.clear();
    m.clear();

    a.resize(4004);
    int i, j;
    for(i = 0;i < 4004;i++)
    {
        for(j = 0;j < 26;j++)
            dist[i][j] = -1;
    }
}

void read()
{
    cin>>st;
    m[st] = 0;
    s = 0;
    cin>>st;
    m[st] = 1;
    e = 1;

    int u, v, w, ct = 2;
    for(int i = 0;i < M;i++)
    {
        cin>>st_a>>st_b>>st;
        if(m.find(st_a) == m.end())
            m[st_a] = ct++;
        if(m.find(st_b) == m.end())
            m[st_b] = ct++;
        
        u = m[st_a], v = m[st_b], w = st.size();
        a[u].push_back({v, {w, st[0] - 'a'}});
        a[v].push_back({u, {w, st[0] - 'a'}});
    }
}

void relax(int u, int ch1, int v, int ch2, int w)
{
    if(dist[v][ch2] == -1 || dist[u][ch1] + w < dist[v][ch2])
    {
        dist[v][ch2] = dist[u][ch1] + w;
        pq.push({dist[v][ch2], {v, ch2}});
    }
}

int Dijkstra()
{
    for(int i = 0;i < 26;i++)
    {
        dist[0][i] = 0;
        pq.push({0, {0, i}});
    }

    pair<int, pair<int, char> > x;
    int d, u, ch;
    while(!pq.empty())
    {
        x = pq.top(), pq.pop();
        d = x.first;
        u = x.second.first;
        ch = x.second.second;

        for(pair<int, pair<int, int> > v : a[u])
        {
            if(ch == v.second.second)
                continue;
            relax(u, ch, v.first, v.second.second, v.second.first);
        }
    }

    int ans = -1;
    for(int i = 0;i < 26;i++)
    {
        if(dist[1][i] != -1)
        {
            if(ans == -1 || dist[1][i] < ans)
                ans = dist[1][i];
        }
    }

    return ans;
}

int main()
{
    int ans;
    while(cin>>M)
    {
        if(!M)
            break;
        reset();
        read();
        ans = Dijkstra();
        if(ans == -1)
            cout<<"impossivel\n";
        else
            cout<<ans<<"\n";
    }

    return 0;
}