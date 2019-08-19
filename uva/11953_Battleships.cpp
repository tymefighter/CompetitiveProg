#include<iostream>

using namespace std;

int n;
char a[101][101];
bool visited[101][101];

void read()
{
    cin>>n;
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
        }
    }
}

int dfs(int r, int c)
{
    if(r < 0 || c < 0 || r >= n || c >= n || visited[r][c] == true || a[r][c] == '.')
        return 0;
    
    visited[r][c] = true;
    int val = 0;
    if(a[r][c] == 'x')
        val = 1;
    
    val = val | dfs(r - 1, c);
    val = val | dfs(r + 1, c);
    val = val | dfs(r, c - 1);
    val = val | dfs(r, c + 1);

    return val;
}

int solve()
{
    int r, c, ans = 0;

    for(r = 0;r < n;r++)
    {
        for(c = 0;c < n;c++)
        {
            if(a[r][c] != '.')
                ans += dfs(r, c);
        }
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    
    for(int i = 1;i <= t;i++)
    {
        read();
        printf("Case %d: %d\n", i, solve());
    }

    return 0;
}