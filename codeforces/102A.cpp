#include<iostream>

using namespace std;

int n, m;
bool a[101][101];
int val[101];

void read()
{
    cin>>n>>m;

    int i, j;

    for(i = 0;i < n;i++)
    {
        cin>>val[i];
        for(j = 0;j < n;j++)
            a[i][j] = false;
    }
    int x, y;
    for(i = 0;i < m;i++)
    {
        cin>>x>>y;
        x--, y--;
        a[x][y] = a[y][x] = true;
    }
}

void solve()
{
    int x, y, z, v;
    int min_val = -1;
    for(x = 0;x < n;x++)
    {
        for(y = x + 1;y < n;y++)
        {
            if(!a[x][y])
                continue;
            for(z = y + 1;z < n;z++)
            {
                if(!(a[x][z] && a[y][z]))
                    continue;
                
                v = val[x] + val[y] + val[z];
                if(min_val == -1 || v < min_val)
                    min_val = v;
            }
        }
    }

    cout<<min_val<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}