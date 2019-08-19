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
    UnionFind(int n)
    {
        reset(n);
    }

    void reset(int n)
    {
        rank.assign(n, 0);
        p.resize(n);
        for(int i = 0;i < n;i++)
            p[i] = i;
    }

    int findSet(int x)
    {
        int repx = x, u;
        while(repx != p[repx])
            repx = p[repx];
        
        while(x != p[x])
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
        a = findSet(a), b = findSet(b);
        if(rank[a] > rank[b])
            p[b] = a;
        else if(rank[a] < rank[b])
            p[a] = b;
        else
        {
            p[b] = a;
            rank[a] ++;
        }
    }
};

int n, m, val, k;
UnionFind ufds(0);
vector<pair<int, pair<int, int> > > el;

void reset()
{
    el.clear();
    ufds.reset(n);
    val = 0;
}

void read()
{
    int i, a, b, w;
    val = 0;
    for(i = 0;i < n-1;i++)
    {
        cin>>a>>b>>w;
        val += w;
    }
    cin>>k;

    for(i = 0;i < k;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        el.push_back({w, {a, b}});
    }

    cin>>m;

    for(i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        a--, b--;
        el.push_back({w, {a, b}});
    }
}

int kruskal()
{
    sort(el.begin(), el.end());
    int a, b, w, ans = 0;
    for(auto edge : el)
    {
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;

        if(ufds.isSame(a, b))
            continue;
        
        ufds.unionSet(a, b);
        ans += w;
    }
    return ans;
}

int main()
{
    int ct = 0;
    while(cin>>n)
    {
        if(ct)
            cout<<"\n";
        reset();
        read();
        cout<<val<<"\n"<<kruskal()<<"\n";
        ct++;
    }
    return 0;
}