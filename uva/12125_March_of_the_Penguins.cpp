#include<iostream>
#include<queue>
#include<bitset>
#include<utility>
#include<cmath>
#define INF 100000000

using namespace std;

int n, N;
float d;                        // max dist an peng can jump
int p[205];                     // parent after bfs
int res[205][205];              // residual graph
int res_copy[205][205];         // residual graph copy
pair<float, float> inp[101];    // input coords
int npeng;                      // number of penguins

/*
    source: 2*n
    sink: i and i + n for all i in [1, n] (actual: i, since i + n signifies the jump)
*/

int s, t;
queue<int> q;
bitset<205> vs;


float dist(int i, int j)
{
    float val1 = (inp[i].first - inp[j].first) * (inp[i].first - inp[j].first);
    float val2 = (inp[i].second - inp[j].second) * (inp[i].second - inp[j].second);

    return sqrt(val1 + val2);
}

void reset()
{
    int i, j;
    for(i = 0;i < 205;i++)
    {
        p[i] = -1;
        for(j = 0;j < 205;j++)
            res[i][j] = 0;
    }
}

void read()
{
    cin>>n>>d;

    int i, j, num, m_jump;

    npeng = 0;
    for(i = 0;i < n;i++)
    {
        cin>>inp[i].first>>inp[i].second>>num>>m_jump;
        res[i][i + n] = m_jump;                 // edge: vertex split of i + 1
        res[2*n][i] = num;                      // edge: source to i + 1
        npeng += num;
    }

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(i == j)
                continue;

            if(dist(i, j) <= d)
                res[i + n][j] = INF;    // edge: i + 1 + n to j + 1
        }
    }

    s = 2 * n;
    N = n;
    n = 2 * n + 1; // double of the vertices + 1 super source

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res_copy[i][j] = res[i][j];
    }
}

int f = 0;

void augment(int v, int minEdge)
{
    if(v == s)
        f = minEdge;
    else if(p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void bfs()
{
    vs.reset();
    while(!q.empty())
        q.pop();

    vs[s] = true;
    q.push(s);
    int u, v;

    while(!q.empty())
    {
        u = q.front(), q.pop();
        if(u == t)
            break;

        for(v = 0;v < n;v++)
        {
            if(res[u][v] > 0 && !vs[v])
            {
                vs[v] = true;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

int EdmondsKarp()
{
    int mf = 0;

    while(true)
    {
        bfs();
        augment(t, INF);
        if(!f)
            break;
        mf += f;
    }

    return mf;
}

void reset_res()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            res[i][j] = res_copy[i][j];
    }
}

int main()
{
    int TEST, ans;
    int ct;
    cin>>TEST;

    while(TEST--)
    {
        reset();
        read();
        ct = 0;
        for(t = 0;t < N;t++)
        {
            reset_res();
            ans = EdmondsKarp();
            if(ans == npeng)
            {
                if(ct)
                    cout<<" ";
                cout<<t;
                ct++;
            }
        }
        if(!ct)
            cout<<"-1";
        cout<<"\n";
    }
    return 0;
}