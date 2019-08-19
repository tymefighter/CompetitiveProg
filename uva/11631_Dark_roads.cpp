#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

class UnionFind
{
    private:
    vector<int> rank, p;

    public:
    int nc;

    UnionFind(int n)
    {
        reset(0);
    }

    int findSet(int x)
    {
        int repx, u;

        repx = x;
        while(repx != p[repx])
            repx = p[repx];
        
        while(x != p[x]) // Path compression
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

    void unionSet(int a, int b)
    {
        if(isSame(a, b))
            return;

        int repa = findSet(a), repb = findSet(b);

        if(rank[repa] > rank[repb])
            p[repb] = repa;
        else if(rank[repa] < rank[repb])
            p[repa] = p[repb];
        else
        {
            p[repb] = repa;
            rank[repa] ++;
        }
    }

    void reset(int n)
    {
        rank.clear();
        p.clear();
        
        rank.assign(n, 0);
        p.resize(n);

        for(int i = 0;i < n;i++)
            p[i] = i;
        
        nc = n;
    }
};

int n, m, ans;
UnionFind ufds(0);
vector<pair<int, pair<int, int> > > el;

void reset()
{
    el.clear();
    el.resize(m);
    ufds.reset(n);
    ans = 0;
}

void read()
{
    int a, b, w;
    reset();

    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        el[i] = {w, {a, b}};
        ans += w;
    }
}

void kruskal()
{
    sort(el.begin(), el.end());
    int a, b, w;

    for(auto edge : el)
    {
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;

        if(ufds.isSame(a, b))
            continue;
        
        ans -= w;
        ufds.unionSet(a, b);
    }
}

int main()
{
    while(cin>>n>>m)
    {
        if(!(n|m))
            break;
        read();
        kruskal();
        cout<<ans<<"\n";
    }

    return 0;
}
