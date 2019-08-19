#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

class UnionFind
{
    private:
    vector<int> rank, p;

    public:
    int nc;

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
        
        nc = n;
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

        if(a == b)
            return;

        nc--;
        
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


int n, s;
vector<pair<float, pair<int, int> > > el;
pair<float, float> coords[501];
UnionFind ufds(0);

float dist(pair<float, float> a, pair<float, float> b)
{
    float d;
    d = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    d = sqrt(d);
    return d;
}

void reset()
{
    el.clear();
    ufds.reset(n);
}

void read()
{
    cin>>s>>n;
    reset();

    int i, j;
    float d;

    for(i = 0;i < n;i++)
    {
        cin>>coords[i].first>>coords[i].second;
        for(j = 0;j < i;j++)
        {
            d = dist(coords[i], coords[j]);
            el.push_back({d, {i, j}});
        }
    }

}

float kruskal()
{
    sort(el.begin(), el.end());
    int a, b;
    float w, min_d = 0.;

    for(auto edge : el)
    {
        if(ufds.nc == s)
            break;
        
        w = edge.first;
        a = edge.second.first;
        b = edge.second.second;

        if(ufds.isSame(a, b))
            continue;
        
        ufds.unionSet(a, b);
        min_d = w;
    }

    return min_d;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        read();
        printf("%0.2f\n", kruskal());
    }
    return 0;
}