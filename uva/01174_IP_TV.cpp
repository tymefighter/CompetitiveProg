#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

const int N = 2005;

int ct, n, m;
vector<vector<pair<int, int> > > a;
map<string, int> mp;
bool taken[N];

void reset()
{
    a.clear();
    a.resize(n);

    ct = 0;
    mp.clear();

    for(int i = 0;i < n;i++)
        taken[i] = false;
}

void read()
{
    int w;
    string u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        if(mp.find(u) == mp.end())
            mp[u] = ct ++;
        if(mp.find(v) == mp.end())
            mp[v] = ct ++;
        
        a[mp[u]].push_back({w, mp[v]});
        a[mp[v]].push_back({w, mp[u]});
    }
}

// Prim's Algorithm
priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;

void solve()
{
    long long ans = 0;
    pq.push({0, 0});
    pair<int, int> u;

    while(!pq.empty())
    {
        u = pq.top(), pq.pop();
        if(taken[u.second])
            continue;
        taken[u.second] = true;
        ans += u.first;

        for(auto v : a[u.second])
        {
            if(!taken[v.second])
                pq.push(v);
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n>>m;
        reset();
        read();
        solve();
    }
    return 0;
}