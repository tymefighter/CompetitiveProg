#include<iostream>
#include<vector>

using namespace std;

class UnionFind
{
    private:
    vector<int> p, rank;
    
    public:

    int nc;
    UnionFind(int n)
    {
        reset(n);
    }

    void reset(int n)
    {
        nc = n;
        p.clear();
        rank.clear();

        p.resize(n);
        rank.assign(n, 0);

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

    void unionSet(int a, int b)
    {
        a = findSet(a), b = findSet(b);

        if(a == b)
            return;

        if(rank[a] > rank[b])
            p[a] = b;
        else if(rank[a] < rank[b])
            p[b] = a;
        else
        {
            p[b] = a;
            rank[a] ++;
        }

        nc--;
    }
};

UnionFind ufds(0);
int n;

void read()
{
    cin>>n;
    ufds.reset(n);
}

void solve()
{
    int x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        x--;
        ufds.unionSet(i, x);
    }

    cout<<ufds.nc<<"\n";
}

int main()
{
    read();
    solve();

    return 0;
}