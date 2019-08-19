#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

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

    int findSet(int a)
    {
        int repa = a, u;

        while(repa != p[repa])
            repa = p[repa];
        
        while(a != p[a])
        {
            u = p[a];
            p[a] = repa;
            a = u;
        }

        return repa;
    }

    bool isSame(int a, int b)
    {
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b)
    {
        a = findSet(a), b = findSet(b);

        if(a == b)
            return;

        if(rank[a] > rank[b])
            p[b] = a;
        else if(rank[a] < rank[b])
            p[a] = b;
        else
        {
            p[b] = a;
            rank[a]++;
        }
    }
};

int n, m;
UnionFind ufds(0);
vector<pair<int, pair<int, int> > >e;
pair<int, pair<int, int> > edge;

void reset()
{
    ufds.reset(n);
    e.clear();
}

void read()
{
    cin>>n>>m;

    reset();

    int i, j, w;

    cin>>i>>j>>w;
    i--, j--;
    edge = {w, {i, j}};

    for(int k = 1;k < m;k++)
    {
        cin>>i>>j>>w;
        i--, j--;
        e.push_back({w, {i, j}});
    }

    sort(e.begin(), e.end());
}

int solve()
{
    for(pair<int, pair<int, int> > x : e)
    {
        ufds.unionSet(x.second.first, x.second.second);
        if(ufds.isSame(edge.second.first, edge.second.second))
            return x.first;
    }

    return 1000000000;
}

int main()
{
    read();
    cout<<solve()<<"\n";
    return 0;
}