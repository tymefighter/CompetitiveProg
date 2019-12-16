#include<iostream>
#include<queue>
#include<map>
#include<cassert>
#include<sstream>

using namespace std;

const int N = 3005, INF = 100000000;

stringstream ss;
string st;
map<string, int> re, pa, cl; // resident, party, club
vector<string> re_re, re_pa, re_cl;
vector<int> party_res;
vector<vector<int> > clubs_res;
int re_count, pa_count, cl_count;

int s, t;
int n, res[N][N];

void resetVecMap()
{
    re_re.clear();
    re_pa.clear();
    re_cl.clear();

    re.clear();
    pa.clear();
    cl.clear();

    re_count = pa_count = cl_count = 0;

    party_res.clear();
    clubs_res.clear();
}

void reset()
{
    n = pa_count + re_count + cl_count + 2;
    s = 0, t = n - 1;

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res[i][j] = 0;
    }
}

void read()
{
    resetVecMap();
    string u;

    while(st != "")
    {
        ss.clear();
        ss.str(st);
        ss >> u;
        
        re[u] = re_count ++;
        re_re.push_back(u);
        ss >> u;

        if(pa.find(u) == pa.end())
        {
            pa[u] = pa_count ++;
            re_pa.push_back(u);
        }
        
        party_res.push_back(pa[u]);
        clubs_res.push_back(vector<int>());

        while(!ss.eof())
        {
            ss >> u;
            if(cl.find(u) == cl.end())
            {
                cl[u] = cl_count ++;
                re_cl.push_back(u);
            }
            
            clubs_res[clubs_res.size() - 1].push_back(cl[u]);
        }

        if(!getline(cin, st))
            break;
    }

    reset();
    for(int i = 0;i < re_count;i++)
    {
        res[party_res[i] + 1][pa_count + 1 + i] = 1;
        
        for(int x : clubs_res[i])
            res[pa_count + 1 + i][x + pa_count + re_count + 1] = 1;
    }

    int w0;
    if(cl_count & 1)
        w0 = cl_count / 2;
    else
        w0 = (cl_count / 2) - 1;
    
    for(int i = 0;i < pa_count;i++)
        res[s][i + 1] = w0;
    
    for(int i = 0;i < cl_count;i++)
        res[i + pa_count + re_count + 1][t] = 1;
}

queue<int> q;
int f, p[N];
bool vis[N];

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

    if(mf != cl_count)
    {
        cout<<"Impossible.\n";
        return;
    }

    assert(re_count == re_re.size() && re_re.size() == re.size());
    assert(cl_count == re_cl.size() && re_cl.size() == cl.size());
    assert(pa_count == re_pa.size() && re_pa.size() == pa.size());

    int i, j;
    for(i = 0;i < cl_count;i++)
    {
        for(j = 0;j < re_count;j++)
        {
            if(res[i + pa_count + re_count + 1][j + pa_count + 1] == 1)
            {
                cout<<re_re[j]<<" "<<re_cl[i]<<"\n";
                break;
            }
        }
    }
}

int main()
{
    int t;
    getline(cin, st);
    ss.clear();
    ss.str(st);
    ss >> t;
    getline(cin, st);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        getline(cin, st);
        read();
        solve();
    }

    return 0;
}