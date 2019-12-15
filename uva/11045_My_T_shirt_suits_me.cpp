#include<iostream>
#include<queue>

using namespace std;

const int N = 55, INF = 100000000;

int num_shirt, num_vol; // num_shirt: number of shirts per size
int n, s, t, res[N][N];

string sizes[6] = {"XXL", "XL", "L", "M" , "S", "XS"};

void reset()
{
    n = 6 + num_vol + 2;
    s = 0, t = 6 + num_vol + 1;

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
}

int findSize(const string &str)
{
    int i;
    for(i = 0;i < 6;i++)
    {
        if(sizes[i] == str)
            break;
    }
    return i;
}

void read()
{
    string str;
    for(int i = 1;i <= num_vol;i++)
    {
        cin>>str;
        res[findSize(str) + 1][i + 6] = 1;
        cin>>str;
        res[findSize(str) + 1][i + 6] = 1;
    }

    for(int i = 1;i <= 6;i++)
        res[s][i] = num_shirt;

    for(int i = 1;i <= num_vol;i++)
        res[i + 6][t] = 1;
}

int f, p[N];
bool vis[N];
queue<int> q;

void resetBFS()
{
    for(int i = 0;i < n;i++)
    {
        p[i] = -1;
        vis[i] = false;
    }

    while(!q.empty())
        q.pop();
}

void augment(int v, int minEdge)
{
    if(v == s)
    {
        f = minEdge;
        return;
    }

    augment(p[v], min(minEdge, res[p[v]][v]));

    res[p[v]][v] -= f;
    res[v][p[v]] += f;
}

void solve()
{
    int mf = 0;

    while(true)
    {
        f = 0;
        resetBFS();
        vis[s] = true;
        q.push(s);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            if(u == t)
            {
                augment(t, INF);
                break;
            }

            for(int v = 0;v < n;v++)
            {
                if(res[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        if(f == 0)
            break;
        mf += f;
    }

    if(mf == num_vol)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>num_shirt>>num_vol;
        num_shirt /= 6;
        reset();
        read();
        solve();
    }
    return 0;
}