#include<iostream>
#include<vector>
#include<utility>
#define MAX 100000000

using namespace std;

int n;
vector<vector<pair<int, int> > > a;
vector<bool> visited;
vector<int> tank, tap;
vector<pair<pair<int, int>, int> >ans_pair;
int indeg[1005], outdeg[1005];

void reset()
{
    ans_pair.clear();
    tank.clear();
    tap.clear();
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        indeg[i] = outdeg[i] = 0;
}

void read()
{
    int m, x, y, w;
    cin>>n>>m;
    reset();

    for(int i = 0;i < m;i++)
    {
        cin>>x>>y>>w;
        x--, y--;
        indeg[y]++;
        outdeg[x]++;
        a[x].push_back({y, w});
    }
}

int e;

int dfs(int u)
{
    int ans = MAX, val;
    visited[u] = true;

    for(pair<int, int> v : a[u])
    {
        if(v.first == e)
        {
            visited[v.first] = true;
            return v.second;
        }

        val = dfs(v.first);
        if(val == MAX)
            continue;
        ans = min(val, v.second);
    }

    return ans;
}

void solve()
{
    for(int i = 0;i < n;i++)
    {
        if(indeg[i] == 0)
            tank.push_back(i);
        else if(outdeg[i] == 0)
            tap.push_back(i);
    }

    int val;
    for(int x : tank)
    {
        for(int y : tap)
        {
            e = y;
            visited.clear();
            visited.assign(n, false);
            val = dfs(x);
            if(val != MAX)
                ans_pair.push_back({{x+1, y+1}, val});
        }
    }

    cout<<ans_pair.size()<<"\n";

    for(pair<pair<int, int>, int> x : ans_pair)
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}