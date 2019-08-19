#include<iostream>
#include<cctype>
#include<set>

using namespace std;

set<char> ch;
char a[21][21];
bool visited[21][21];
int m, n, sr, sc;
char LAND, WATER;

void read()
{
    int i, j;

    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
            ch.insert(tolower(a[i][j]));
        }
    }

    cin>>sr>>sc;
    LAND = tolower(a[sr][sc]);
    ch.erase(LAND);
    WATER = *ch.begin();
    ch.clear();
}

int dfs(int r, int c)
{
    if(r >= m || r < 0 || visited[r][c] || tolower(a[r][c]) == WATER)
        return 0;

    visited[r][c] = true;
    int val = 1;
    
    val += dfs(r - 1, c);
    val += dfs(r + 1, c);
    val += dfs(r, (c + 1) % n);
    val += dfs(r, (c + (n - 1)) % n);
    return val;
}

int solve()
{

    int r, c, max_val = dfs(sr, sc);

    max_val = 0;
    for(r = 0;r < m;r++)
    {
        for(c = 0;c < n;c++)
        {
            if(! visited[r][c] && tolower(a[r][c]) == LAND)
                max_val = max(max_val, dfs(r, c));
        }
    }

    return max_val;
}


int main()
{
    while(cin>>m>>n)
    {
        read();
        cout<<solve()<<"\n";
    }
    
    return 0;
}