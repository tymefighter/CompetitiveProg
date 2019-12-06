#include<iostream>
#include<queue>

using namespace std;

const int N = 55;

struct State
{
    int x, y, bm;
};

int n;
int a[N][N];
int sx, sy, ex, ey;
int dist[N][N][1024];
deque<State> deq;

void reset()
{
    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k <= 1024;k++)
                dist[i][j][k] = -1;
        }
    }

    while(!deq.empty())
        deq.pop_front();
}

void read()
{
    cin>>n;
    reset();
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            cin>>a[i][j];
    }

    cin>>sx>>sy;
    cin>>ex>>ey;
}

int ax[] = {-1, 1, 0, 0};
int ay[] = {0, 0, -1, 1};

bool isValid(State u)
{
    if(u.x < 0 || u.x >= n || u.y < 0 || u.y >= n)
        return false;
    return true;
}

void solve()
{
    State u, v;
    u.x = sx;
    u.y = sy;
    u.bm = 1 << a[u.x][u.y];

    dist[u.x][u.y][u.bm] = 1;
    deq.push_back(u);

    while(!deq.empty())
    {
        u = deq.front();
        deq.pop_front();
        if(u.x == ex && u.y == ey)
        {
            cout<<dist[u.x][u.y][u.bm]<<"\n";
            break;
        }

        for(int i = 0;i < 4;i++)
        {
            v.x = u.x + ax[i];
            v.y = u.y + ay[i];

            if(isValid(v))
            {
                if((1 << a[v.x][v.y]) & u.bm)
                {
                    v.bm = u.bm;
                    if(dist[v.x][v.y][v.bm] == -1 || dist[u.x][u.y][u.bm] < dist[v.x][v.y][v.bm])
                    {
                        dist[v.x][v.y][v.bm] = dist[u.x][u.y][u.bm];
                        deq.push_front(v);
                    }
                }
                else
                {
                    v.bm = u.bm | (1 << a[v.x][v.y]);
                    if(dist[v.x][v.y][v.bm] == -1)
                    {
                        dist[v.x][v.y][v.bm] = dist[u.x][u.y][u.bm] + 1;
                        deq.push_back(v);
                    }
                }
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}