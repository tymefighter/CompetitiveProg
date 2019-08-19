#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;
int R, C, n;
int inp[101][101];
int dist[10005];
bool visited[10005];
vector<vector<int> > a;
vector<int> topo;

int ar[] = {0, 0, -1, 1};
int ac[] = {-1, 1, 0, 0};

void reset()
{
    topo.clear();
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
    {
        dist[i] = -1;
        visited[i] = false;
    }
}

bool check(int r, int c)
{
    if(r < 0 || r >= R || c < 0 || c >= C)
        return false;
    
    return true;
}

void addE(int r, int c, int rd, int cd)
{
    int val1 = r * C + c, val2 = rd * C + cd;
    a[val1].push_back(val2);
}

void read()
{
    cin>>s>>R>>C;
    n = R * C;
    reset();

    int r, c, i, rd, cd;
    for(r = 0;r < R;r++)
    {
        for(c = 0;c < C;c++)
            cin>>inp[r][c];
    }

    for(r = 0;r < R;r++)
    {
        for(c = 0;c < C;c++)
        {
            for(i = 0;i < 4;i++)
            {
                rd = r + ar[i];
                cd = c + ac[i];
                if(check(rd, cd) && inp[rd][cd] < inp[r][c])
                    addE(r, c, rd, cd);
            }
        }
    }
}

void dfs(int u)
{
    visited[u] = true;

    for(int v : a[u])
    {
        if(!visited[v])
            dfs(v);
    }
    topo.push_back(u);
}

void t_sort()
{
    for(int u = 0;u < n;u++)
    {
        if(!visited[u])
            dfs(u);
    }
    reverse(topo.begin(), topo.end());
}

void relax(int u, int v, int w)
{
    if(dist[u] + w > dist[v])
        dist[v] = dist[u] + w;
}

void solve()
{
    t_sort();

    for(int u : topo)
    {
        if(dist[u] == -1)
            dist[u] = 1;
        
        for(int v : a[u])
            relax(u, v, 1);
    }

    int ans = 0;
    for(int u = 0;u < n;u++)
        ans = max(ans, dist[u]);

    cout<<s<<": "<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        read();
        solve();
    }
    return 0;
}