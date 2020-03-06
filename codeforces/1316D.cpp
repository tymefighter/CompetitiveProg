#include<iostream>
#include<queue>
#include<cassert>
#include<set>

using namespace std;

const int N = 1005;
int n;
bool vis[N][N];
pair<int, int> a[N][N];
set<pair<int, int> > blocked;


void read()
{
    blocked.clear();
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d %d", &a[i][j].first, &a[i][j].second);

            vis[i][j] = false;
            if(a[i][j].first != -1)
            {
                a[i][j].first --;
                a[i][j].second --;
                blocked.insert(a[i][j]);
            }
        }
    }
}

char ans[N][N];
int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};
queue<pair<int, int> > q;

void direct_arrow(int from_r, int from_c, int to_r, int to_c)
{
    assert((from_r == to_r) || (from_c == to_c));

    if(from_r != to_r)
    {
        assert(abs(to_r - from_r) == 1);
        if(from_r < to_r) // go down
            ans[from_r][from_c] = 'D';
        else              // go up
            ans[from_r][from_c] = 'U';
    }
    else
    {
        assert(abs(to_c - from_c) == 1);
        if(from_c < to_c) // go right
            ans[from_r][from_c] = 'R';
        else              // go left
            ans[from_r][from_c] = 'L';
    }
}

bool is_valid(int r, int c, const pair<int, int> &blocked_num)
{
    if(r < 0 || r >= n || c < 0 || c >= n
        || vis[r][c] || a[r][c] != blocked_num)
        return false;
    else
        return true;
}

void bfs(int r, int c, const pair<int, int> &blocked_num)
{
    ans[r][c] = 'X';
    vis[r][c] = true;
    q.push({r, c});
    while(!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0;i < 4;i++)
        {
            int rd = r + ar[i];
            int cd = c + ac[i];
            if(is_valid(rd, cd, blocked_num))
            {
                vis[rd][cd] = true;
                direct_arrow(rd, cd, r, c);
                q.push({rd, cd});
            }
        }
    }
}

// 1) returns true if current branch
// has seen a cycle, and false otherwise
// 2) imp: If current branch has seen a cycle direct the parent towards this node
// else, direct this towards the parent.
bool dfs(int r, int c, int parent_r, int parent_c)
{
    vis[r][c] = true;
    bool found_cycle = false;
    for(int i = 0;i < 4;i++)
    {
        int rd = r + ar[i];
        int cd = c + ac[i];
        if(rd < 0 || rd >= n || cd < 0 || cd >= n || a[rd][cd].first != -1)
            continue;
        
        if(vis[rd][cd])
        {
            if(!found_cycle)
            {
                direct_arrow(r, c, rd, cd);
                found_cycle = true;
            }
        }
        else
        {
            bool has_cycle = dfs(rd, cd, r, c);
            if(!found_cycle)
            {
                direct_arrow(r, c, rd, cd);
                found_cycle = true;
            }
        }
    }

    if(!found_cycle && parent_r != -1)
        direct_arrow(r, c, parent_r, parent_c);
    
    return found_cycle;
}

bool solve()
{
    for(auto pr : blocked)
    {
        if(a[pr.first][pr.second].first != pr.first || a[pr.first][pr.second].second != pr.second) // blocked state can reach somewhere else, this should not be allowed
            return false;
        bfs(pr.first, pr.second, a[pr.first][pr.second]);
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(!vis[i][j])
            {
                if(a[i][j].first == -1)
                {
                    if(!dfs(i, j, -1, -1)) // could not reach a cycle
                        return false;
                }
                else               // non (-1, -1) node was not visited 
                    return false;
            }
        }
    }

    return true;
}

void printAns()
{
    printf("VALID\n");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }
}

int main()
{
    read();
    if(solve())
        printAns();
    else
        printf("INVALID\n");
    return 0;
}