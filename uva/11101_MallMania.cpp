#include<iostream>
#include<utility>
#include<queue>

using namespace std;

int a[2001][2001];
int dist[2001][2001];
pair<int, int> pts[2001];
queue<pair<int, int> > q;
int ar[4] = {0, 0, -1, 1};
int ac[4] = {-1, 1, 0, 0};
int n1, n2;

void read()
{
    int i, j, r, c;
    for(i = 0;i < 2000;i++)
    {
        for(j = 0;j < 2000;j++)
        {
            a[i][j] = 0;
            dist[i][j] = -1;
        }
    }

    for(i = 0;i < n1;i++)
    {
        cin>>r>>c;

        q.push({r, c});
        pts[i].first = r, pts[i].second = c;
        dist[r][c] = 0;

        a[r][c] = -1;
    }

    cin>>n2;

    for(i = 0;i < n2;i++)
    {
        cin>>r>>c;
        a[r][c] = 1;
    }
}

bool check(int r, int c)
{
    if(r < 0 || r > 2000 || c < 0 || c > 2000 || a[r][c] == -1 || dist[r][c] != -1)
        return false;
    
    return true;
}

void bfs()
{   
    pair<int, int> coord;
    int r, c, i, rd, cd, ans = -1;
    while(! q.empty())
    {
        coord = q.front();
        q.pop();
        r = coord.first, c = coord.second;
        if(a[r][c] == 1)
        {
            ans = dist[r][c];
            break;
        }

        for(i = 0;i < 4;i++)
        {
            rd = r + ar[i], cd = c + ac[i];
            if(check(rd, cd))
            {
                dist[rd][cd] = dist[r][c] + 1;
                q.push({rd, cd});
            }
        }
    }
    cout<<ans<<"\n";

    while (! q.empty())
        q.pop();
}


int main()
{
    while(cin>>n1)
    {
        if(!n1)
            break;
        read();
        bfs();
    }

    return 0;
}