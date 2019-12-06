#include<iostream>

using namespace std;

int n;
char a[55][55];

void read()
{
    cin>>n;
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
            cin>>a[i][j];
    }
}

bool checkPlace(int i, int j)    // Give it top of +
{
    if(i + 1 >= n || i + 2 >= n || j + 1 >= n || j - 1 < 0)
        return false;
    
    if(a[i + 1][j] == '#' || a[i + 2][j] == '#' || a[i + 1][j - 1] == '#' || a[i + 1][j + 1] == '#')
        return false;

    a[i][j] = a[i + 1][j] = a[i + 2][j] = a[i + 1][j - 1] = a[i + 1][j + 1] = '#';
    return true;
}

void solve()
{
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(a[i][j] == '.')
            {
                if(!checkPlace(i, j))
                {
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }

    cout<<"YES\n";
}

int main()
{
    read();
    solve();

    return 0;
}