#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int a, b, c, x, y, z;
int dist[101][101][101];
priority_queue<pair<int, pair<int, pair<int, int> > > > pq;

void reset()
{
    while(!pq.empty())
        pq.pop();

    int i, j, k;
    for(i = 0;i < 101;i++)
    {
        for(j = 0;j < 101;j++)
        {
            for(k = 0;k < 101;k++)
                dist[i][j][k] = -1;
        }
    }
}

bool check(int i, int j, int k)
{
    if(i < 0 || i > 100 || j < 0 || j > 100 || k < 0 || k > 100)
        return false;

    return true;
}

void relax(int i, int j, int k, int p, int q, int r, int w)
{
    if(dist[p][q][r] == -1 || dist[i][j][k] + w < dist[p][q][r])
    {
        dist[p][q][r] = dist[i][j][k] + w;
        pq.push({dist[p][q][r], {p, {q, r}}});
    }
}

void bfs()
{
    int i, j, k;
    dist[a][b][c] = 0;
    pq.push({0, {a, {b, c}}});
    pair<int, pair<int, pair<int, int> > > yy;

    while(!pq.empty())
    {
        yy = pq.top(), pq.pop();
        i = yy.second.first, j = yy.second.second.first, k = yy.second.second.second;
        cout<<i<<" "<<j<<" "<<k<<" "<<dist[i][j][k]<<"\n";

        if(i == x && j == y && k == z)
            break;

        if(check(i - 1, j - 1, k + 1))
            relax(i, j, k, i - 1, j - 1, k + 1, 0);

        if(check(i - 1, j + 1, k - 1))
            relax(i, j, k, i - 1, j + 1, k - 1, 0);
        
        if(check(i + 1, j - 1, k - 1))
            relax(i, j, k, i + 1, j - 1, k - 1, 0);
        //
        if(check(i - 1, j + 1, k + 1))
            relax(i, j, k, i - 1, j + 1, k + 1, 0);

        if(check(i + 1, j - 1, k + 1))
            relax(i, j, k, i + 1, j - 1, k + 1, 0);

        if(check(i + 1, j + 1, k - 1))
            relax(i, j, k, i + 1, j + 1, k - 1, 0);

        if(check(i + 1, j, k))
            relax(i, j, k, i + 1, j - 1, k - 1, 1);

        if(check(i, j + 1, k))
            relax(i, j, k, i, j + 1, k, 1);

        if(check(i, j, k + 1))
            relax(i, j, k, i, j, k + 1, 1);
        
    }

    cout<<dist[x][y][z]<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        cin>>a>>b>>c>>x>>y>>z;
        bfs();
    }
    return 0;
}