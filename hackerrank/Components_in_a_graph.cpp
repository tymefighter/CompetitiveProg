#include<iostream>
#include<vector>
#include<set>

using namespace std;

class UnionFind
{
    private:
    vector<int> p, rank, size;
    public:
    void reset(int n)
    {
        rank.assign(n, 0);
        size.assign(n, 1);
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

    void unionSet(int a, int b)
    {
        a = findSet(a), b = findSet(b);
        if(a == b)
            return;
        if(rank[a] > rank[b])
        {
            p[b] = a;
            size[a] += size[b];
        }
        else if(rank[b] > rank[a])
        {
            p[a] = b;
            size[b] += size[a];
        }
        else
        {
            p[b] = a;
            rank[a] ++;
            size[a] += size[b];
        }
    }

    int ret_size(int a)
    {
        return size[findSet(a)];
    }
};

UnionFind ufds;
int n;
set<int> seen;

void read()
{
    cin>>n;
    ufds.reset(2 * n);
    int a, b;
    for(int i = 0;i < n;i++)
    {
        cin>>a>>b;
        a--, b--;
        seen.insert(a);
        seen.insert(b);
        ufds.unionSet(a, b);
    }
}

void solve()
{
    int min_val = 2 * n, max_val = 1, val;
    for(int u : seen)
    {
        val = ufds.ret_size(u);
        min_val = min(min_val, val);
        max_val = max(max_val, val);
    }
    cout<<min_val<<" "<<max_val<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}