#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int n;
vector<vector<int> > a;

void reset()
{
    a.clear();
    a.resize(n);
}

void read()
{
    cin>>n;
    reset();
    int x, y;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

long double dfs(int u, int prev)
{
    if((a[u].size() == 1 && prev != -1) || a[u].size() == 0)
        return 0.;

    long double ans = 0.;

    for(int v : a[u])
    {
        if(v == prev)
            continue;

        ans += (dfs(v, u) + 1);
    }

    if(prev == -1)
        ans = ans / ((long double)a[u].size());
    else
        ans = ans / ((long double)a[u].size() - 1.);

    return ans;
}

int main()
{
    read();
    cout<<setprecision(6)<<fixed<<dfs(0, -1)<<"\n";
    return 0;
}