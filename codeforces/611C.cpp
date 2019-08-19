#include<iostream>

using namespace std;

int n, m;
char grid[501][501];
int hor[501][501], ver[501][501];

void read()
{
    cin>>n>>m;
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>grid[i][j];
    }

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            hor[i][j] = (i > 0 ? hor[i - 1][j] : 0) + (j > 0 ? hor[i][j - 1] : 0) - (i > 0 && j > 0 ? hor[i - 1][j - 1] : 0);
            if(j < m - 1 && grid[i][j] == '.' && grid[i][j + 1] == '.')
                hor[i][j]++;
            
            ver[i][j] = (i > 0 ? ver[i - 1][j] : 0) + (j > 0 ? ver[i][j - 1] : 0) - (i > 0 && j > 0 ? ver[i - 1][j - 1] : 0);
            if(i < n - 1 && grid[i][j] == '.' && grid[i + 1][j] == '.')
                ver[i][j]++;
        }
    }
    
}

void solve()
{
    int q, r1, r2, c1, c2, ans;
    cin>>q;

    while(q--)
    {
        cin>>r1>>c1>>r2>>c2;
        r1--, c1--, r2--, c2--;
        c2--;
        if(c2 >= c1)
            ans = hor[r2][c2] + (r1 > 0 && c1 > 0 ? hor[r1 - 1][c1 - 1] : 0) - (r1 > 0 ? hor[r1 - 1][c2] : 0) - (c1 > 0 ? hor[r2][c1 - 1] : 0);
        else
            ans = 0;
        c2++;
        r2--;
        if(r2 >= r1)
            ans += ver[r2][c2] + (r1 > 0 && c1 > 0 ? ver[r1 - 1][c1 - 1] : 0) - (r1 > 0 ? ver[r1 - 1][c2] : 0) - (c1 > 0 ? ver[r2][c1 - 1] : 0);
        cout<<ans<<"\n";
    }
}

int main()
{
    read();
    solve();
    return 0;
}