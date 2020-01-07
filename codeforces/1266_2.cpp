#include<iostream>

using namespace std;

int nReal, mReal, n, m;
int a[505][505];

void printAns()
{
    int i, j;

    if(n != nReal)
    {
        for(j = 0;j < m;j++)
        {
            for(i = 0;i < n;i++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
    {
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < m;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
}

void solve()
{
    if(n == 1 && m == 1)
    {
        cout<<"0\n";
        return;
    }
    else if(n == 1)
    {
        for(int i = 0;i < m;i++)
            a[0][i] = i + 2;
    }
    else
    {
        int i, j;
        for(j = 0;j < m;j++)
            a[0][j] = j + 2;

        for(i = 1;i < n;i++)
        {
            for(j = 0;j < m;j++)
                a[i][j] = (m + 1 + i) * a[0][j];
        }
    }

    printAns();
}

int main()
{
    cin>>nReal>>mReal;
    n = min(nReal, mReal);
    m = max(nReal, mReal);
    solve();
    return 0;
}