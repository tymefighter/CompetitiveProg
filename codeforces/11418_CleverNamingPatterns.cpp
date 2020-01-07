#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#include<cctype>

using namespace std;

const int N = 55, INF = 100000000;
vector<vector<string> > prob_name;

vector<vector<int> > a;
int n0, s, t, n, res[N][N];

void reset()
{
    prob_name.clear();
    prob_name.resize(n0);
    a.clear();
    a.resize(n);

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
}

void read()
{
    int k;
    cin>>n0;
    n = 2 * n0 + 2;
    s = 0, t = n - 1;
    reset();

    int i, j;
    string st;
    for(i = 0;i < n0;i++)
    {
        cin>>k;
        for(j = 0;j < k;j++)
        {
            cin>>st;
            prob_name[i].push_back(st);

            res[tolower(st[0]) - 'a' + 1][i + n0 + 1] = 1;
        }
    }

    for(i = 0;i < n0;i++)
        res[s][i + 1] = 1;

    for(i = 0;i < n0;i++)
        res[i + n0 + 1][t] = 1;

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

    assert(mf == n0);
    int i, j;

    for(i = 0;i < n0;i++)
    {
        for(j = 0;j < n0;j++)
        {
            if(res[j + n0 + 1][i + 1] > 0)
            {
                for(auto st : prob_name[j])
                {
                    if(tolower(st[0]) == (char)('a' + i))
                    {
                        st[0] = toupper(st[0]);
                        cout<<st[0];
                        for(int k = 1;k < st.size();k++)
                            cout<<(char)tolower(st[k]);
                        cout<<"\n";
                        break;
                    }
                }
                break;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}