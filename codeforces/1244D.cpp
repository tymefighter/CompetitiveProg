#include<iostream>
#include<vector>

using namespace std;

const long long INF = 1000000000000000000;
const int N = 100005;
int n;
int c[3][N], deg[N], color[N], best_color[N];
vector<vector<int> > a;
bool notPossible;

void reset()
{
    for(int i = 0;i < n;i++)
        deg[i] = 0;
    a.clear();
    a.resize(n);
    notPossible = false;
}

void read()
{
    cin>>n;
    reset();

    int i, j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < n;j++)
            cin>>c[i][j];
    }

    int u, v;
    for(i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u] ++;
        deg[v] ++;
        if(deg[u] > 2 || deg[v] > 2)
            notPossible = true;
    }
}

void resetColor()
{
    for(int i = 0;i < n;i++)
        color[i] = -1;
}

void copyColor()
{
    for(int i = 0;i < n;i++)
        best_color[i] = color[i] + 1;
}

int getColor(int c1, int c2)
{
    static bool cl[3];
    
    for(int i = 0;i < 3;i++)
        cl[i] = false;
    
    cl[c1] = cl[c2] = true;

    for(int i = 0;i < 3;i++)
    {
        if(!cl[i])
            return i;
    }
    return -1;
}

long long dfs(int u, int prev)
{
    long long ans = c[color[u]][u];

    for(int v : a[u])
    {
        if(color[v] == -1)
        {
            color[v] = getColor(prev, color[u]);
            ans += dfs(v, color[u]);
        }
    }

    return ans;
}

void solve()
{
    int start = -1;
    for(int u = 0;u < n;u++)
    {
        if(deg[u] == 1)
        {
            start = u;
            break;
        }
    }

    if(start == -1 || notPossible)
    {
        cout<<"-1\n";
        return;
    }

    long long ans = INF, val;
    int i, j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(i == j)
                continue;
            resetColor();
            color[start] = i;
            color[a[start][0]] = j;
            val = c[i][start] + dfs(a[start][0], i);
            if(val < ans)
            {
                ans = val;
                copyColor();
            }
        }
    }

    cout<<ans<<"\n";
    for(int i = 0;i < n;i++)
        cout<<best_color[i]<<" ";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}