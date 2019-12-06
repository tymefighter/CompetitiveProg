#include<iostream>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

typedef struct Location
{
    int a[4];
} Location;

queue<Location> q;
int dist[71][71][71][71];

void reset()
{
    int i, j, k, l;

    for(i = 1;i <= 70;i++)
    {
        for(j = 1;j <= 70;j++)
        {
            for(k = 1;k <= 70;k++)
            {
                for(l = 1;l <= 70;l++)
                    dist[i][j][k][l] = -1;
            }
        }
    }
}

int getSymm(int move, int fix)
{
    return 2 * fix - move;
}

void bfs()
{
    Location u, v;
    set<int> s;
    int i, j, dval;

    u.a[0] = 1, u.a[1] = 2, u.a[2] = 3, u.a[3] = 4;
    q.push(u);
    dist[u.a[0]][u.a[1]][u.a[2]][u.a[3]] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        s.clear();
        s.insert(u.a[0]);
        s.insert(u.a[1]);
        s.insert(u.a[2]);
        s.insert(u.a[3]);

        dval = dist[u.a[0]][u.a[1]][u.a[2]][u.a[3]];

        for(i = 0;i < 4;i++)
        {
            if(u.a[i] + 1 <= 70 && s.find(u.a[i] + 1) == s.end())
            {
                u.a[i] += 1;
                v = u;
                sort(v.a, v.a + 4);
                u.a[i] -= 1;
                if(dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] == -1)
                {
                    dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] = dval + 1;
                    q.push(v);
                }
            }
            if(u.a[i] - 1 > 0 && s.find(u.a[i] - 1) == s.end())
            {
                u.a[i] -= 1;
                v = u;
                sort(v.a, v.a + 4);
                u.a[i] += 1;
                if(dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] == -1)
                {
                    dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] = dval + 1;
                    q.push(v);
                }
            }
        }

        for(i = 0;i < 4;i++)
        {
            for(j = 0;j < 4;j++)
            {
                if(i == j)
                    continue;
                
                v = u;
                v.a[i] = getSymm(u.a[i], u.a[j]);

                if(v.a[i] > 0 && v.a[i] <= 70 && s.find(v.a[i]) == s.end())
                {
                    sort(v.a, v.a + 4);
                    if(dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] == -1)
                    {
                        dist[v.a[0]][v.a[1]][v.a[2]][v.a[3]] = dval + 1;
                        q.push(v);
                    }  
                }
            }
        }
    }
}

int main()
{
    reset();
    bfs();

    int i, t, a[4];
    cin>>t;
    while(t--)
    {
        for(i = 0;i < 4;i++)
            cin>>a[i];
        sort(a, a + 4);
        cout<<dist[a[0]][a[1]][a[2]][a[3]]<<"\n";
    }
    return 0;
}