#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > a;
vector<int> gp;

void reset()
{
    a.clear();
    a.resize(n);
    gp.clear();
    gp.assign(n, -1);
}

void read()
{
    cin>>n>>m;
    reset();

    int x, y;
    for(int i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

bool bip_check(int u)
{
    bool val = true;
    for(int v : a[u])
    {
        if(gp[v] == -1)
        {
            gp[v] = (gp[u] + 1) % 2;
            if(!bip_check(v))
                val = false;
        }
        else if(gp[v] == gp[u])
            return false;
    }

    return val;
}

vector<int> A, B;

bool solve()
{
    for(int u = 0;u < n;u++)
    {
        if(gp[u] == -1)
        {
            gp[u] = 0;
            if(!bip_check(u))
                return false;
        }
    }

    A.clear(), B.clear();
    for(int i = 0;i < n;i++)
    {
        if(gp[i] < 0)
            return false;

        if(gp[i])
            A.push_back(i + 1);
        else
            B.push_back(i + 1);
    }

    return true;
}

int main()
{
    read();
    if(!solve())
        cout<<"-1\n";
    else
    {
        cout<<A.size()<<"\n";
        for(int x : A)
            cout<<x<<" ";
        cout<<"\n";

        cout<<B.size()<<"\n";
        for(int x : B)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}