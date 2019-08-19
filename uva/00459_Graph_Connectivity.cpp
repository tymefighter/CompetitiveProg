#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s;

class UnionFind
{
    private:

    vector<int> rank, parent;
    int n;

    public:

    int num_comp;

    UnionFind(int num_nodes)
    {
        n = num_nodes;

        rank.assign(n, 0);
        parent.resize(n);
        num_comp = n;

        for(int i = 0;i < n;i++)
            parent[i] = i;
    }

    int findSet(int u)
    {
        int rep, x;

        rep = u;
        while(rep != parent[rep])
            rep = parent[rep];

        while(u != parent[u])
        {
            x = parent[u];
            parent[u] = rep;
            u = x;
        }

        return rep;
    }

    void unionSet(int a, int b)
    {
        int rep1 = findSet(a), rep2 = findSet(b);

        if(rep1 == rep2)
            return;
        
        if(rank[rep1] > rank[rep2])
            parent[rep2] = rep1;
        else if(rank[rep1] < rank[rep2])
            parent[rep1] = rep2;
        else
        {
            parent[rep2] = rep1;
            rank[rep1] ++;
        }
        num_comp --;
    }
};

void read_solve()
{
    char a, b;
    getline(cin, s);
    a = s[0];
    UnionFind ufds(a  - 'A' + 1);

    while(getline(cin, s))
    {
        if(s[0] < 'A' || s[0] > 'Z')
            break;
        
        a = s[0];
        b = s[1];
        ufds.unionSet(a - 'A', b - 'A');
    }

    cout<<ufds.num_comp<<"\n";
}

int main()
{
    int t;
    cin>>t;
    getline(cin, s);
    getline(cin, s);
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        read_solve();
    }
}
