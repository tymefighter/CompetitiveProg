#include<iostream>
#include<vector>
#include<set>

using namespace std;

class UnionFind
{
    private:
    const int N = 100005;
    vector<int> rank, p;
    set<int> vertex_used;
    public:
    UnionFind()
    {
        rank.clear();
        rank.assign(N, 0);
        p.clear();
        p.resize(N);
        for(int i = 0;i < N;i++)
            p[i] = i;
    }

    void reset()
    {
        for(auto x : vertex_used)
        {
            rank[x] = 0;
            p[x] = x;
        }
        vertex_used.clear();
    }

    int findSet(int x)
    {
        vertex_used.insert(x);

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
    bool isSame(int u, int v)
    {
        return findSet(u) == findSet(v);
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

UnionFind ufds;

void reset()
{
    ufds.reset();
}

bool read_solve()
{
    reset();

    int ans = 0, u, v;
    while(cin>>u)
    {
        if(u == -1)
        {
            cout<<ans<<"\n";
            return true;
        }
        cin>>v;
        if(!ufds.isSame(u, v))
            ufds.unionSet(u, v);
        else
            ans ++;
    }
    return false;
}

int main()
{
    while(read_solve());
    return 0;
}