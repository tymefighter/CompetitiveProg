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

    int findSet(int x)
    {
        int repx = x, u;

        while (repx != p[repx])
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
        int repa = findSet(a), repb = findSet(b);

        if(repa == repb)
            return;

        if(rank[repa] > rank[repb])
            p[repb] = repa;
        else if(rank[repa] < rank[repb])
            p[repa] = repb;
        else
        {
            p[repb] = repa;
            rank[repa] ++;
        }
    }

    void reset(int n)
    {
        rank.assign(n, 0);
        p.resize(n);

        for(int i = 0;i < n;i++)
            p[i] = i;
    }
};

UnionFind ufds(0);
vector<pair<int, pair<int, int> > > el; // edge list
int n, m;

void reset()
{
    ufds.reset(n);
    el.clear();
    el.resize(m);
}

void read()
{
    int a, b, w;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>w;
        el[i] = {w, {a, b}};
    }
}

void kruskal()
{
    vector<int> ans;
    sort(el.begin(), el.end());
    int a, b, w;

    for(auto edge : el)
    {
        a = edge.second.first;
        b = edge.second.second;
        w = edge.first;

        if(ufds.isSame(a, b))
        {
            ans.push_back(w);
            continue;
        }
        
        ufds.unionSet(a, b);
    }

    if(!ans.size())
    {
        cout<<"forest\n";
        return;
    }
    
    sort(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
}

int main()
{
    while(cin>>n>>m)
    {
        if(!(n|m))
            break;
        reset();
        read();
        kruskal();
    }
    return 0;
}