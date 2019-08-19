#include<iostream>

using namespace std;

int n, m;
char a[1005][1005];
bool visited[1005][1005][3];
int ac[] = {0, 0, -1, 1};
int ar[] = {-1, 1, 0, 0};
int lt1[] = {0, 0, -1, -1};
int lt2[] = {-1, -1, 0, 0};
int rs, cs, re, ce;

void read()
{
    cin>>n>>m;

    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 'S')
            {
                rs = i;
                cs = j;
            }
            else if(a[i][j] == 'T')
            {
                re = i;
                ce = j;
            }
            for(k = 0;k < 3;k++)
                visited[i][j][k] = false;
        }
    }
}

bool check(int r, int c, int left)
{
    if(r < 0 || r >= n || c < 0 || c >= m || left < 0 || a[r][c] == '*')
        return false;
    
    return true;
}

bool row_start;

void dfs(int r, int c, int left)
{
    visited[r][c][left] = true;
    if(r == re && c == ce)
        return;

    int rd, cd, leftd;
    for(int i = 0;i < 4;i++)
    {
        rd = r + ar[i];
        cd = c + ac[i];
        if((left % 2 == 0 && row_start) || ((left % 2 == 1) && !row_start))
            leftd = left + lt1[i];
        else
            leftd = left + lt2[i];
        if(!check(rd, cd, leftd) || visited[rd][cd][leftd])
            continue;
        
        dfs(rd, cd, leftd);
    }
}

bool solve()
{
    row_start = true;
    dfs(rs, cs, 2);
    for(int k = 0;k < 3;k++)
    {
        if(visited[re][ce][k])
            return true;
    }

    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            for(k = 0;k < 3;k++)
                visited[i][j][k] = false;
        }
    }
    row_start = false;
    dfs(rs, cs, 2);
    
    for(int k = 0;k < 3;k++)
    {
        if(visited[re][ce][k])
            return true;
    }

    return false;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}