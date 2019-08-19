#include<iostream>
#include<vector>

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
            rank[a]++;
            size[a] += size[b];
        }
    }

    int ret_size(int x)
    {
        return size[findSet(x)];
    }
};

UnionFind ufds;

void solve()
{
    int n, q, i, j;
    char ch;

    cin>>n>>q;
    ufds.reset(n);
    while(q--)
    {
        cin>>ch;
        if(ch == 'M')
        {
            cin>>i>>j;
            i--, j--;
            ufds.unionSet(i, j);
        }
        else
        {
            cin>>i;
            i--;
            cout<<ufds.ret_size(i)<<"\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}

