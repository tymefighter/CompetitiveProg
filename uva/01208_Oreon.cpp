#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UnionFind
{
    private:
    vector<int> p, rank;

    public:
    void reset(int n)
    {
        rank.clear();
        rank.assign(n, false);
        p.clear();
        p.resize(n);
        for(int i = 0;i < n;i++)
            p[i] = i;
    }

    int findSet(int x)
    {
        int repx = x, u;

        while(p[repx] != repx)
            repx = p[repx];
        
        while(p[x] != x)
        {
            u = p[x];
            p[x] = repx;
            x = u;
        }
        return repx;
    }
    
    bool isSame(int a, int b)
    {
        return findSet(a) == findSet(b);
    }

    void unionSet(int u, int v)
    {
        u = findSet(u), v = findSet(v);
        if(u == v)
            return;
        
        if(rank[u] > rank[v])
            p[v] = u;
        else if(rank[u] < rank[v])
            p[u] = v;
        else
        {
            p[v] = u;
            rank[u] ++;
        }
    }
};

int n;
vector<pair<int, pair<int, int> > > elist;
UnionFind ufds;

void reset()
{
    ufds.reset(n);
    elist.clear();
}

void read()
{
    int i, j, w;
    char take_comma;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>w;
            if(j < n - 1)
                cin>>take_comma;
            if(w > 0)
                elist.push_back({w, {i, j}});
        }
    }
}

void solve()
{
    sort(elist.begin(), elist.end());

    for(auto e : elist)
    {
        if(!ufds.isSame(e.second.first, e.second.second))
        {
            cout<<(char)(e.second.first + 'A')<<"-"<<(char)(e.second.second + 'A')<<" "<<e.first<<"\n";
            ufds.unionSet(e.second.first, e.second.second);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n;
        reset();
        read();
        printf("Case %d:\n", i);
        solve();
    }
    return 0;
}