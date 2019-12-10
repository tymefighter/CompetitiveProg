#include<iostream>
#include<queue>
#include<sstream>
#include<vector>

using namespace std;

const int N = 505;

int n, dist[N][N], nearStation[N];
bool hasStation[N];
vector<vector<pair<int, int> > > a;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

stringstream ss;
string s;

void reset()
{
    a.clear();
    a.resize(n);

    int i, j;
    for(i = 0;i < n;i++)
    {
        hasStation[i] = false;
        nearStation[i] = -1;
        for(j = 0;j < n;j++)
            dist[i][j] = -1;
    }
}

void read()
{
    int f, u, v, w;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> f >> n;
    
    reset();

    for(int i = 0;i < f;i++)
    {
        getline(cin, s);
        ss.clear();
        ss.str(s);
        ss >> u;
        u --;
        hasStation[u] = true;
    }

    while(getline(cin, s))
    {
        if(s == "")
            break;
        ss.clear();
        ss.str(s);
        ss >> u >> v >> w;
        u --, v --;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
}

void Dijkstra(int idx)
{
    dist[idx][idx] = 0;
    pq.push({0, idx});

    pair<int, int> u;
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(dist[idx][u.second] < u.first)
            continue;

        for(auto v : a[u.second])
        {
            if(dist[idx][v.second] == -1
                || dist[idx][u.second] + v.first < dist[idx][v.second])
            {
                dist[idx][v.second] = dist[idx][u.second] + v.first;
                pq.push({dist[idx][v.second], v.second});
            }
        }
    }

    // cout<<idx<<" -------\n";
    for(int i = 0;i < n;i++)
    {
        // cout<<hasStation[i]<<" "<<dist[idx][i]<<" --\n";
        if(hasStation[i] && dist[idx][i] != -1)
        {
            if(nearStation[idx] == -1 || dist[idx][i] < dist[idx][nearStation[idx]])
                nearStation[idx] = i;
        }
    }

    // cout<<idx<<" "<<nearStation[idx]<<" "<<dist[idx][nearStation[idx]]<<" --\n";
}

void solve()
{
    for(int i = 0;i < n;i++)
        Dijkstra(i);
    
    int i, j, ans = -1, val, node;
    for(i = 0;i < n;i++)
    {
        val = -1;
        for(j = 0;j < n;j++)
            val = max(val, min(dist[j][i], dist[j][nearStation[j]]));

        if(ans == -1 || val < ans)
        {
            node = i;
            ans = val;
        }
    }

    cout<<node + 1<<"\n";
}

int main()
{
    int t;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> t;
    getline(cin, s);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        read();
        solve();
    }
    return 0;
}