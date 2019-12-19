#include<iostream>
#include<queue>
#include<sstream>
#include<map>

using namespace std;

class State
{
    public:
    char board[5][5];
    int r, c;
};

bool operator==(const State &a, const State &b)
{
    if(a.r != b.r || a.c != b.c)
        return false;
    int i, j;
    for(i = 0;i < 5;i++)
    {
        for(j = 0;j < 5;j++)
        {
            if(a.board[i][j] != b.board[i][j])
                return false;
        }
    }

    return true;
}

struct cmpState
{
    bool operator()(const State &a, const State &b) const
    {
        if(a.r != b.r)
            return a.r < b.r;
        if(a.c != b.c)
            return a.c < b.c;

        int i, j;
        for(i = 0;i < 5;i++)
        {
            for(j = 0;j < 5;j++)
            {
                if(a.board[i][j] != b.board[i][j])
                    return a.board[i][j] < b.board[i][j];
            }
        }

        return false;
    }
};
stringstream ss;
string st;

State s, t;
map<State, int, cmpState> dist;
queue<State> q;

void initializeFinalState()
{
    int i, j;
    for(i = 0;i < 5;i++)
    {
        for(j = i + 1;j < 5;j++)
            t.board[i][j] = '1';
        
        for(j = 0;j < i;j++)
            t.board[i][j] = '0';
    }

    t.board[0][0] = t.board[1][1] = '1';
    t.board[2][2] = ' ';
    t.board[3][3] = t.board[4][4] = '0';
    t.r = t.c = 2;
}

void read()
{
    int i, j;

    for(i = 0;i < 5;i++)
    {
        getline(cin, st);
        for(j = 0;j < 5;j++)
        {
            s.board[i][j] = st[j];
            if(s.board[i][j] == ' ')
            {
                s.r = i;
                s.c = j;
            }
        }
    }
}

int ar[] = {2, 2, -2, -2, 1, -1, 1, -1};
int ac[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool isPossible(int r, int c)
{
    if(r < 0 || r >= 5 || c < 0 || c >= 5)
        return false;
    return true;
}

void solve()
{
    dist.clear();
    while(!q.empty())
        q.pop();
    
    dist[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        State u = q.front();
        q.pop();

        if(u == t || dist[u] > 10)
            break;

        int rd, cd, prev_r, prev_c;
        State v = u;

        for(int i = 0;i < 8;i++)
        {
            rd = v.r + ar[i];
            cd = v.c + ac[i];
            if(!isPossible(rd, cd))
                continue;
            prev_r = v.r;
            prev_c = v.c;

            v.r = rd;
            v.c = cd;
            swap(v.board[prev_r][prev_c], v.board[rd][cd]);
            if(dist.find(v) == dist.end())
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }

            v.r = prev_r;
            v.c = prev_c;
            swap(v.board[prev_r][prev_c], v.board[rd][cd]);
        }
    }

    if(dist.find(t) == dist.end()
        || dist[t] > 10)
    {
        cout<<"Unsolvable in less than 11 move(s).\n";
        return;
    }

    printf("Solvable in %d move(s).\n", dist[t]);
}

int main()
{
    initializeFinalState();
    int t;
    
    getline(cin, st);
    ss.clear();
    ss.str(st);
    ss >> t;

    while(t--)
    {
        read();
        solve();
    }
    return 0;
}