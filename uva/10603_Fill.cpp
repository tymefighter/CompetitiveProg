#include<iostream>
#include<queue>

using namespace std;

const int N = 205;
struct State
{
    int a[3];
};

struct ComparePQ
{
    bool operator()(const pair<int, State> &u, const pair<int, State> &v)
    {
        if(u.first != v.first)
            return u.first > v.first;
        else
        {
            for(int i = 0;i < 3;i++)
            {
                if(u.second.a[i] != v.second.a[i])
                    return u.second.a[i] > v.second.a[i];
            }
            return false;
        }
    }
};

int dist[N][N][N];
priority_queue<pair<int, State>, vector<pair<int, State> >, ComparePQ > pq;
int d, a[3];

void reset()
{
    int i, j, k;

    for(i = 0;i <= a[0];i++)
    {
        for(j = 0;j <= a[1];j++)
        {
            for(k = 0;k <= a[2];k++)
                dist[i][j][k] = -1;
        }
    }

    while(!pq.empty())
        pq.pop();
}

void solve()
{   
    pair<int, State> u, v;
    int i, j, ds;
    u.first = 0;
    u.second.a[0] = 0, u.second.a[1] = 0, u.second.a[2] = a[2];
    
    dist[u.second.a[0]][u.second.a[1]][u.second.a[2]] = 0;
    pq.push(u);

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(u.second.a[0] == d || u.second.a[1] == d || u.second.a[2] == d)
        {
            cout<<dist[u.second.a[0]][u.second.a[1]][u.second.a[2]]<<" "<<d<<"\n";
            return;
        }

        if(dist[u.second.a[0]][u.second.a[1]][u.second.a[2]] < u.first)
            continue;
        

        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                if(i == j)
                    continue;

                if(u.second.a[i] + u.second.a[j] <= a[j])
                {
                    v = u;
                    v.second.a[j] += u.second.a[i];
                    v.second.a[i] = 0;
                    
                    ds = dist[u.second.a[0]][u.second.a[1]][u.second.a[2]] + u.second.a[i];

                    if(dist[v.second.a[0]][v.second.a[1]][v.second.a[2]] == -1
                        || ds < dist[v.second.a[0]][v.second.a[1]][v.second.a[2]])
                    {
                        v.first = dist[v.second.a[0]][v.second.a[1]][v.second.a[2]] = ds;
                        pq.push(v);
                    }
                }
                else
                {
                    v = u;
                    v.second.a[j] = a[j];
                    v.second.a[i] = u.second.a[i] + u.second.a[j] - a[j];


                    ds = dist[u.second.a[0]][u.second.a[1]][u.second.a[2]] + (a[j] - u.second.a[j]);

                    if(dist[v.second.a[0]][v.second.a[1]][v.second.a[2]] == -1
                        || ds < dist[v.second.a[0]][v.second.a[1]][v.second.a[2]])
                    {
                        v.first = dist[v.second.a[0]][v.second.a[1]][v.second.a[2]] = ds;
                        pq.push(v);
                    }
                }
            }
        }
    }

    int dval, ans = -1;

    for(dval = d;dval >= 0;dval --)
    {
        if(dval <= a[2])
        {
            for(i = 0;i <= a[0];i++)
            {
                for(j = 0;j <= a[1];j++)
                {
                    if(dist[i][j][dval] != -1)
                    {
                        if(ans == -1 || dist[i][j][dval] < ans)
                            ans = dist[i][j][dval];
                    }
                }
            }
        }

        if(dval <= a[1])
        {
            for(i = 0;i <= a[0];i++)
            {
                for(j = 0;j <= a[2];j++)
                {
                    if(dist[i][dval][j] != -1)
                    {
                        if(ans == -1 || dist[i][dval][j] < ans)
                            ans = dist[i][dval][j];
                    }
                }
            }
        }

        if(dval <= a[0])
        {
            for(i = 0;i <= a[1];i++)
            {
                for(j = 0;j <= a[2];j++)
                {
                    if(dist[dval][i][j] != -1)
                    {
                        if(ans == -1 || dist[dval][i][j] < ans)
                            ans = dist[dval][i][j];
                    }
                }
            }
        }

        if(ans != -1)
        {
            cout<<ans<<" "<<dval<<"\n";
            return;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i = 0;i < 3;i++)
            cin>>a[i];
        cin>>d;
        reset();
        solve();
    }
    return 0;
}