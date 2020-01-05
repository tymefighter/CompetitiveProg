#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class UnionFind
{
    private:
    vector<int> p, rank;

    public:
    vector<int> size;
    int n_comp;

    void reset(int n)
    {
        n_comp = n;
        rank.clear();
        rank.assign(n, 0);
        size.clear();
        size.assign(n, 1);
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
        else if(rank[a] < rank[b])
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
        n_comp --;
    }
};

const int N = 200005;
int n, m, deg[N];
UnionFind ufds;
vector<vector<int> > g; // Actual graph
set<pair<int, int> > e_set;
// stores edges of the given graph: If edge is (u, v), then it stores (min(u, v), max(u, v))

void reset()
{
    e_set.clear();
    ufds.reset(n);
    g.clear();
    g.resize(n);

    for(int i = 0;i < n;i++)
        deg[i] = 0;
}

void read()
{
    int u, v;
    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v --;
        deg[u] ++, deg[v] ++;
        g[u].push_back(v);
        g[v].push_back(u);
        e_set.insert({min(u, v), max(u, v)});
    }
}

void solve()
{
    int a = 0; // minimum degree vertex

    for(int i = 1;i < n;i++)
    {
        if(deg[i] < deg[a])
            a = i;
    }

    // Set D: set of verts not connected to a directly
    set<int> D;
    vector<int> B;                              // Set of all vertices not connected to a by an edge
    int num_no_edge = 0;                        // number of vertices connected to a by an edge (cardinality of set D)

    for(int i = 0;i < n;i++)
    {
        if(i != a && e_set.find({min(a, i), max(a, i)}) == e_set.end())       // Edge not found in the actual graph
        {
            ufds.unionSet(a, i);                                    // Hence, a and i are connected
            num_no_edge ++;
            D.insert(i);
        }
        else
            B.push_back(i);
    }
    
    for(int u : B)
    {
        int num_connected_D = 0;
        for(int v : g[u])
        {
            if(D.find(v) != D.end()) // v is a vertex not directly connected to a
                num_connected_D ++;
        }

        if(num_connected_D < num_no_edge)   // Then there is an edge from v to D in the complement graph
            ufds.unionSet(a, u);
    }

    // Scan over the complement of the subgraph of B in the given graph, and finally build all components
    // |B| = O(m / n), hence below complexity is O((m / n) ^ 2 * log(m))
    for(int u : B)
    {
        for(int v : B)
        {
            if(e_set.find({min(u, v), max(u, v)}) == e_set.end())   // Edge not found
                ufds.unionSet(u, v);    // Hence edge is present
        }
    }

    vector<bool> saw_vert;
    vector<int> sizes;
    saw_vert.assign(n, false);

    for(int u = 0;u < n;u++)
    {
        int u_rep = ufds.findSet(u);
        if(!saw_vert[u_rep])
        {
            sizes.push_back(ufds.size[u_rep]);
            saw_vert[u_rep] = true;
        }
    }

    cout<<ufds.n_comp<<"\n";
    sort(sizes.begin(), sizes.end());
    for(int sz : sizes)
        cout<<sz<<" ";
    cout<<"\n";
}

int main()
{
    cin>>n>>m;
    reset();
    read();
    solve();
    return 0;
}