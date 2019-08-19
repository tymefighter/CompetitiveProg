#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int n, m, k;
int sr, sc, er, ec;
bool a[1005][1005];
int dist[1005][1005];

int ar[] = {0, 0, 1, -1};
int ac[] = {1, -1, 0, 0};

queue<pair<int, int> > q;

void read()
{
    int r, c, num, x;
    cin>>k;

    for(r = 0;r < n;r++)
    {
        for(c = 0;c < m;c++)
        {
            a[r][c] = true;
            dist[r][c] = -1;
        }
    }

    while(k--)
    {
        cin>>r>>num;
        for(x = 0;x < num;x++)
        {
            cin>>c;
            a[r][c] = false;
        }
    }

    cin>>sr>>sc;
    cin>>er>>ec;
}

int bfs()
{
    int r, c, i;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    pair<int, int> coord;

    while(! q.empty())
    {
        coord = q.front();
        if(coord.first == er && coord.second == ec)
            break;
        q.pop();

        for(i = 0;i < 4;i++)
        {
            r = coord.first + ar[i];
            c = coord.second + ac[i];

            if(r < 0 || r >= n || c < 0 || c >= m || !a[r][c] || dist[r][c] != -1)
                continue;

            dist[r][c] = dist[coord.first][coord.second] + 1;
            q.push({r, c});
        }
    }
    while (!q.empty())
        q.pop();
    

    return dist[er][ec];
}



int main()
{
    while(cin>>n>>m)
    {
        if(!(n|m))
            break;
        read();
        cout<<bfs()<<"\n";
    }
    return 0;
}