#include<iostream>
#include<queue>

using namespace std;

int sr, sc, fr, fc;
int ar[] = {2, 2, -2, -2, 1, 1, -1, -1};
int ac[] = {1, -1, 1, -1, 2, -2, 2, -2};
queue<pair<int, int> > q;
int dist[8][8];

void reset()
{
    int i, j;
    for(i = 0;i < 8;i++)
    {
        for(j = 0;j < 8;j++)
            dist[i][j] = -1;
    }
}

void bfs(int r, int c)
{
    q.push({r, c});
    dist[r][c] = 0;

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        
        for(int i = 0;i < 8;i++)
        {
            auto x = u;
            x.first += ar[i];
            x.second += ac[i];
            if(x.first < 0 || x.first >= 8 
                || x.second < 0 || x.second >= 8
                    || dist[x.first][x.second] != -1)
                continue;
            dist[x.first][x.second] = dist[u.first][u.second] + 1;
            q.push(x);
        }
    }
}

void solve()
{
    reset();
    bfs(sr, sc);
    cout<<dist[fr][fc]<<"\n";
}

int main()
{
    char line[128];
    int t;
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t);
    while(t--)
    {
        fgets(line, sizeof(line), stdin);
        sr = line[1] - '1';
        sc = line[0] - 'a';
        fr = line[4] - '1';
        fc = line[3] - 'a';
        solve();
    }
    return 0;
}