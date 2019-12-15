#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1050, INF = 100000000;

int nk, np, total_num_probs_req;
int n, s, t, res[N][N];
vector<vector<int> > a;

void reset()
{
    n = nk + np + 2;
    s = 0, t = n - 1;
    a.clear();
    a.resize(n);

    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
}

bool read()
{
    int i, j, w;
    
    total_num_probs_req = 0;
    for(i = 0;i < nk;i++)
    {
        cin>>w;
        res[np + 1 + i][t] = w;
        total_num_probs_req += w;
    }

    int m, cat;
    for(i = 1;i <= np;i++)
    {
        cin>>m;
        for(j = 0;j < m;j++)
        {
            cin>>cat;
            res[i][np + cat] = 1;
        }
    }

    if(total_num_probs_req > np)
        return false;

    for(i = 1;i <= np;i++)
        res[s][i] = 1;
    
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(res[i][j] > 0)
            {
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }

    return true;
}

int f, p[N];
queue<int> q;
bool vis[N];

void resetBFS()
{
    for(int i = 0;i < n;i++)
    {
        vis[i] = false;
        p[i] = -1;
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

            for(int v : a[u])
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

    if(mf != total_num_probs_req)
    {
        cout<<"0\n";
        return;
    }

    cout<<"1\n";
    for(int categ = 1;categ <= nk;categ++)
    {
        for(int prob = 1;prob <= np;prob++)
        {
            if(res[np + categ][prob] > 0)
                cout<<prob<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    while(cin>>nk>>np)
    {
        if(!(nk || np))
            break;
        reset();
        if(read())
            solve();
        else
            cout<<"0\n";
    }
    return 0;
}