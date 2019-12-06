#include<iostream>
#include<vector>

using namespace std;

class UnionFind
{
    private:
        int n;
        vector<int> rank, p;
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
            int u, repx = x;

            while(repx != p[repx])
                repx = p[repx];
            
            while(x != p[x])        // Path Compression
            {
                u = p[x];
                p[x] = repx;
                x = u;
            }

            return repx;
        }

        bool isSame(int u, int v)
        {
            return findSet(u) == findSet(v);
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

UnionFind ufds;
int n, d, a;
long long ans;
char printMat[105][105];

void reset()
{
    ufds.reset(n);
    ans = 0;

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            printMat[i][j] = '0';
    }
}

void read_solve()
{
    cin>>n>>d>>a;
    reset();

    int i, j;
    char is_edge;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>is_edge;
            if(i < j && is_edge == '1')
            {
                if(ufds.isSame(i, j))
                {
                    ans += d;
                    printMat[i][j] = printMat[j][i] = 'd';
                }
                else
                    ufds.unionSet(i, j);
            }
        }
    }

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i < j && !ufds.isSame(i, j))
            {
                ufds.unionSet(i, j);
                ans += a;
                printMat[i][j] = printMat[j][i] = 'a';
            }   
        }
    }


    cout<<ans<<"\n";
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            cout<<printMat[i][j];
        cout<<"\n";
    }
}

int main()
{
    read_solve();
    return 0;
}