#include<iostream>
#include<utility>
#include<queue>
#define MOD 20437

using namespace std;

int n;
char a[12][12];
pair<int, int> pos[27];
int sp[27], dist[12][12], dp[12][12][200];
int n_alpha;
int ar[4] = {0, 0, -1, 1};
int ac[4] = {-1, 1, 0, 0};
char curr;

void read()
{
    int i, j;
    char x;
    n_alpha = 0;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>x;
            if(x != '.' && x != '#')
            {
                pos[x - 'A'] = {i, j};
                a[i][j] = x;
                n_alpha++;
            }
            else
                a[i][j] = x;
        }
    }
}

void reset_dist()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            dist[i][j] = -1;
    }
}

bool check(int r, int c)
{
    if(r < 0 || c < 0 || r >= n || c >= n || a[r][c] == '#' || a[r][c] > curr)
        return false;
    return true;
}

int bfs(int r, int c, int rd, int cd)
{
    reset_dist();
    queue<pair<int, int> > q;
    pair<int, int> x;
    dist[r][c] = 0;
    q.push({r, c});


    while(!q.empty())
    {
        x = q.front(), q.pop();
        r = x.first, c = x.second;
        if(rd == r && cd == c)
            break;

        for(int i = 0;i < 4;i++)
        {
            int r1 = r + ar[i], c1 = c + ac[i];
            if(check(r1, c1) && dist[r1][c1] == -1)
            {
                dist[r1][c1] = dist[r][c] + 1;
                q.push({r1, c1});
            }
        }
    }

    return dist[rd][cd];
}

int r2, c2;

void reset_nsp(int len)
{
    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k <= len;k++)
                dp[i][j][k] = -1;
        }
    }
}

int count(int r, int c, int k)
{
    if(k < 0)
        return 0;

    if(r == r2 && c == c2)
        return 1;
    
    if(dp[r][c][k] != -1)
        return dp[r][c][k];

    int ans = 0;

    for(int i = 0;i < 4;i++)
    {
        int rd = r + ar[i], cd = c + ac[i];
        if(check(rd, cd))
            ans = (ans + count(rd, cd, k - 1) % MOD) % MOD;
    }

    dp[r][c][k] = ans % MOD;
    return ans;
}

void solve(int cn)
{
    int i, val1 = 0, val2 = 1;

    sp[0] = 0;
    for(i = 1;i < n_alpha;i++)
    {
        curr = a[pos[i].first][pos[i].second];
        sp[i] = bfs(pos[i - 1].first, pos[i - 1].second, pos[i].first, pos[i].second);

        if(sp[i] == -1)
            break;
        val1 += sp[i];
        r2 = pos[i].first, c2 = pos[i].second;
        reset_nsp(sp[i]);
        val2 = ((val2 % MOD) * (count(pos[i - 1].first, pos[i - 1].second, sp[i]) % MOD)) % MOD;
    }

    if(i == n_alpha)
        printf("Case %d: %d %d\n", cn, val1, val2);
    else
        printf("Case %d: Impossible\n", cn);
}


int main()
{
    int cn = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        read();
        solve(cn);
        cn++;
    }
    return 0;
}