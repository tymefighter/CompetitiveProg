#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n;
vector<vector<int> > a;
vector<int> dist, dist1, dist2;
set<int> best, worst;
int ds, de; // diameter start, diameter end

void reset()
{
    a.clear();
    a.resize(n);
    best.clear();
    worst.clear();
    dist1.clear();
    dist2.clear();
}

void read()
{
    int i, j, ct, x;
    for(i = 0;i < n;i++)
    {
        cin>>ct;
        for(j = 0;j < ct;j++)
        {
            cin>>x;
            x--;
            a[i].push_back(x);
        }
    }
}

void dfs(int u)
{

    for(int v : a[u])
    {
        if(dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

void solve()
{
    int i;
    dist.clear();
    dist.assign(n, -1);
    dist[0] = 0;
    dfs(0);

    ds = 0;
    int val = dist[0];
    for(i = 1;i < n;i++)
    {
        if(val < dist[i])
        {
            ds = i;
            val = dist[i];
        }
    }

    dist.assign(n, -1);
    dist[ds] = 0;
    dfs(ds);
    val = dist[ds];
    de = ds;
    for(i = 0;i < n;i++)
    {
        if(val < dist[i])
        {
            de = i;
            val = dist[i];
        }
    }
    dist1 = dist;
    int x = dist1[de] / 2;

    dist.assign(n, -1);
    dist[de] = 0;
    dfs(de);
    dist2 = dist;

    for(i = 0;i < n;i++)
    {
        if(dist1[i] == x && (dist2[i] == x || dist2[i] == x + 1))
        {
            best.insert(i);
        }
        else if(dist2[i] == x && (dist1[i] == x || dist1[i] == x + 1))
        {
            best.insert(i);
        }
        else if(dist1[i] == dist1[de] || dist2[i] == dist2[ds])
        {
            worst.insert(i);
        }
    }

    cout<<"Best Roots  : ";
    int ct = 0;
    for(int x : best)
    {
        if(ct)
            cout<<" ";
        cout<<x+1;
        ct++;
    }
    cout<<"\n";
    cout<<"Worst Roots : ";

    ct = 0;
    for(int x : worst)
    {
        if(ct)
            cout<<" ";
        cout<<x+1;
        ct++;
    }
    cout<<"\n";

}

int main()
{
    while(cin>>n)
    {
        reset();
        read();
        solve();
    }
    return 0;
}