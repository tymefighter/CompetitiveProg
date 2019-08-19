#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;


class UnionFind
{
    private:
    vector<int> rank, parent;
    public:

    int n_comp;
    
    UnionFind(int n)
    {
        rank.assign(n, 0);
        parent.resize(n);

        for(int i = 0;i < n;i++)
            parent[i] = i;
        
        n_comp = n;
    }

    int findSet(int x)
    {
        int rep_x = x, u;

        while(rep_x != parent[rep_x])
            rep_x = parent[rep_x];

        while(x != parent[x])
        {
            u = parent[x];
            parent[x] = rep_x;
            x = u;
        }

        return rep_x;
    }

    void unionSet(int a, int b)
    {
        int repa = findSet(a), repb = findSet(b);

        if(repa == repb)
            return;
        
        if(rank[repa] > rank[repb])
            parent[repb] = repa;
        else if(rank[repa] < rank[repb])
            parent[repa] = repb;
        else
        {
            parent[repb] = repa;
            rank[repa] ++;
        }

        n_comp--;
    }

    void reset(int n)
    {
        rank.clear();
        parent.clear();
        
        rank.assign(n, 0);
        parent.resize(n);

        for(int i = 0;i < n;i++)
            parent[i] = i;

        n_comp = n;
    }
};

int n, m, k, val;
vector<vector<pair<int, int> > > adj;
vector<pair<int, pair<int, int> > > edge, edges_in_gph;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
set<pair<int, int> > edge_flag;
vector<bool> taken;
UnionFind ufds(0);



void reset()
{
    edge.clear();
    edges_in_gph.clear();
    adj.clear();
    edge_flag.clear();
    taken.clear();

    ufds.reset(n);
    edge.resize(m);
    edges_in_gph.resize(k);
    adj.resize(n);
    taken.assign(n, false);
    val = 0;
}

void read()
{
    cin>>n>>m>>k;
    reset();

    int i, w, a, b;
    for(i = 0;i < m;i++)
    {
        cin>>w>>a>>b;
        edge[i] = {w, {a, b}};
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    for(i = 0;i < k;i++)
    {
        cin>>w>>a>>b;
        ufds.unionSet(a, b);
        edges_in_gph[i] = {w, {a, b}};
        edge_flag.insert({a, b});
        edge_flag.insert({b, a});
        val += w;
    }
}

int Kruskal_method()
{
    sort(edge.begin(), edge.end());

    int i = 0, ans = val, a, b, w;
    for(i = 0;i < m;i++)
    {
        w = edge[i].first;
        a = edge[i].second.first;
        b = edge[i].second.second;

        if((edge_flag.find({a, b}) != edge_flag.end()) || (ufds.findSet(a) == ufds.findSet(b)))
            continue;

        ufds.unionSet(a, b);
        ans += w;
    }

    return ans;
}

int Prim_method()
{
    int i, w, a, b, ans = val;
    for(i = 0;i < k;i++)
    {
        w = edges_in_gph[i].first;
        a = edges_in_gph[i].second.first;
        b = edges_in_gph[i].second.second;

        if(! taken[a])
        {
            taken[a] = true;
            for(pair<int, int> v : adj[a])
                pq.push({v.first, v.second});
        }

        if(! taken[b])
        {
            taken[b] = true;
            for(pair<int, int> v : adj[b])
                pq.push({v.first, v.second});
        }
    }

    pair<int, int> u;

    while (! pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(taken[u.second])
            continue;

        ans += u.first;
        taken[u.second] = true;

        for(pair<int, int> v : adj[u.second])
        {
            if(! taken[v.second])
                pq.push({v.first, v.second});
        }
    }
    
    return ans;
}

int main()
{
    int ans1, ans2;
    read();

    ans1 = Kruskal_method();
    ans2 = Prim_method();

    printf("Kruskal: %d, Prim: %d\n", ans1, ans2);
    return 0;
}
