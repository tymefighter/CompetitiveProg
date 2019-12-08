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
        rank.assign(n, 0);
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
        
        while(x != p[x])  // Path Compression
        {
            u = p[x];
            p[x] = repx;
            x = u;
        }
        return repx;
    }

    bool isSame(int u, int b)
    {
        return findSet(u) == findSet(b);
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
UnionFind ufds;
char comb[505][4];
vector<pair<int, pair<int, int> > > e_list;

void reset()
{
    ufds.reset(n);
    e_list.clear();
}

int dist(int i, int j)
{
    int ds = 0, val;
    for(int k = 0;k < 4;k++)
    {
        if(j != -1)
            val = abs(((int)comb[i][k]) - ((int)comb[j][k]));
        else
            val = abs(comb[i][k] - '0');
        val = min(val, 10 - val);
        ds += val;
    }

    return ds;
}

void read()
{
    cin>>n;
    reset();

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 4;j++)
            cin>>comb[i][j];

        for(j = 0;j < i;j++)
            e_list.push_back({dist(i, j), {i, j}});
    }
}

void solve()
{
    sort(e_list.begin(), e_list.end());

    int ans = 0;
    for(auto x : e_list)
    {
        if(!ufds.isSame(x.second.first, x.second.second))
        {
            ans += x.first;
            ufds.unionSet(x.second.first, x.second.second);
        }
    }

    int val = dist(0, -1);
    for(int i = 1;i < n;i++)
        val = min(val, dist(i, -1));

    ans += val;
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}