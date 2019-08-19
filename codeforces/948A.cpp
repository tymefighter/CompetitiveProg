#include<iostream>

using namespace std;

int n, m;
int a[501][501];

int ar[] = {0, 0, -1, 1};
int ac[] = {-1, 1, 0, 0};

void read()
{
    cin>>n>>m;
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>a[i][j];
    }
}

bool check_fill(int i, int j)
{
    int k;
    for()
}

bool solve()
{
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(a[i][j] == 'S' && !check_fill(i, j))
                return false;
            
        }
    }


}

int main()
{
    read();
    solve();
    return 0;
}