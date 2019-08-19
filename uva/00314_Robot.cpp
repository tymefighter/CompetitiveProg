#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int m, n;
bool a[55][55];
int dist[55][55][4];
int sr, sc, er, ec, dir;
queue<pair<pair<int, int>, int> > q;

void read()
{
    int i, j, k, x;
    string s;

    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>x;
            if(x)
                a[i][j] = true;
            else
                a[i][j] = false;

            for(k = 0;k < 4;k++)
                dist[i][j][k] = -1;
        }
    }
    cin>>sr>>sc>>er>>ec;
    cin>>s;
    sr--, sc--, er--, ec--;
    if(s == "north")
        dir = 0;
    else if(s == "east")
        dir = 1;
    else if(s == "south")
        dir = 2;
    else if(s == "west")
        dir = 3;
}

// 0: up, 1: right, 2: down, 3: left
// right turn: (x + 1) % 4, left turn: (x + 3) % 4

int rot(int d, bool rt)
{
    if(rt)
        return (d + 1) % 4; // right
    else
        return (d + 3) % 4; // left
}

bool check(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n || a[r][c])
        return false;

    return true;
}

void solve()
{
    if(!(check(sr, sc) && check(sr, sc + 1) && check(sr + 1, sc) && check(sr + 1, sc + 1)))
    {
        cout<<-1<<"\n";
        return;
    }



    pair<pair<int, int>, int> coord;
    int r, c, d, i;
    dist[sr][sc][dir] = 0;
    q.push({{sr, sc}, dir});
    bool got_ans = false;

    while(! q.empty())
    {
        coord = q.front();
        q.pop();
        r = coord.first.first;
        c = coord.first.second;
        d = coord.second;

        if(r == er && c == ec)
        {
            cout<<dist[er][ec][d]<<"\n";
            got_ans = true;
            break;
        }

        if(dist[r][c][rot(d, true)] == -1)
        {
            dist[r][c][rot(d, true)] = dist[r][c][d] + 1;
            q.push({{r, c}, rot(d, true)});
        }
        if(dist[r][c][rot(d, false)] == -1)
        {
            dist[r][c][rot(d, false)] = dist[r][c][d] + 1;
            q.push({{r, c}, rot(d, false)});
        }

        if(d == 0)
        {
            for(i = 1;i <= 3;i++)
            {
                if(check(r - i, c) && check(r - i, c + 1) && check(r + 1 - i, c) && check(r + 1 - i, c + 1))
                {
                    if(dist[r - i][c][d] == -1)
                    {
                        dist[r - i][c][d] = dist[r][c][d] + 1;
                        q.push({{r - i, c}, d});
                    }
                }
                else
                    break;
            }
        }
        else if(d == 1)
        {
            for(i = 1;i <= 3;i++)
            {
                if(check(r, c + i) && check(r, c + 1 + i) && check(r + 1, c + i) && check(r + 1, c + 1 + i))
                {
                    if(dist[r][c + i][d] == -1)
                    {
                        dist[r][c + i][d] = dist[r][c][d] + 1;
                        q.push({{r, c + i}, d});
                    }
                }
                else
                    break;
            }
        }
        else if(d == 2)
        {
            for(i = 1;i <= 3;i++)
            {
                if(check(r + i, c) && check(r + i, c + 1) && check(r + 1 + i, c) && check(r + 1 + i, c + 1))
                {
                    if(dist[r + i][c][d] == -1)
                    {
                        dist[r + i][c][d] = dist[r][c][d] + 1;
                        q.push({{r + i, c}, d});
                    }
                }
                else
                    break;
            }
        }
        else if(d == 3)
        {
            for(i = 1;i <= 3;i++)
            {
                if(check(r, c - i) && check(r, c + 1 - i) && check(r + 1, c - i) && check(r + 1, c + 1 - i))
                {
                    if(dist[r][c - i][d] == -1)
                    {
                        dist[r][c - i][d] = dist[r][c][d] + 1;
                        q.push({{r, c - i}, d});
                    }
                }
                else
                    break;
            }
        }
    }
    while(!q.empty())
        q.pop();

    if(!got_ans)
        cout<<-1<<"\n";
}


int main()
{
    while(cin>>m>>n)
    {
        if(!(n|m))
            break;
        read();
        solve();
    }
    return 0;
}