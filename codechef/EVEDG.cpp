#include<iostream>
#include<vector>

using namespace std;

int n, m, ans;
vector<vector<int> > a;
vector<int> comp_no, gp, indeg;

void reset()
{
    a.clear();
    a.resize(n);

    gp.clear();
    gp.assign(n, 1);

    indeg.clear();
    indeg.assign(n, 0);
}

void read()
{
    cin>>n>>m;
    reset();

    int u, v;

    for(int i = 0;i < m;i++)
    {
        cin>>u>>v;
        u --, v--;
        a[u].push_back(v);
        a[v].push_back(u);
        indeg[u] ++;
        indeg[v] ++;
    }
}

void solve()
{
    int u;
    ans = 1;

    if(m % 2 == 0)
        return;

    for(u = 0;u < n;u++)
    {
        if(indeg[u] % 2)
        {
            gp[u] = 2;
            ans = 2;
            return;
        }
    }

    for(u = 0;u < n;u++)
    {
        if(a[u].size() > 1)
        {
            ans = 3;
            gp[u] = 2;
            gp[a[u][0]] = 3;
            return;
        }
    }
}

void printAns()
{
    cout<<ans<<"\n";

    for(int x : gp)
        cout<<x<<" ";
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
        printAns();
    }
    return 0;
}