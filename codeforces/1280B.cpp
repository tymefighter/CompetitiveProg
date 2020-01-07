#include<iostream>

using namespace std;

int num_a, n, m;
char a[65][65];

void read()
{
    cin>>n>>m;

    int i, j;
    num_a = 0;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 'A')
                num_a ++;
        }
    }
}

void solve()
{
    if(num_a == 0)
    {
        cout<<"MORTAL\n";
        return;
    }
    else if(num_a == n * m)
    {
        cout<<"0\n";
        return;
    }
    
    int i, j;
    bool ans_found = false, found = true, boundary_a_found = false;
    
    for(i = 0;i < n;i++)
    {
        if(a[i][0] != 'A')
        {
            found = false;
        }
        else
            boundary_a_found = true;
    }

    ans_found |= found;
    found = true;

    for(i = 0;i < n;i++)
    {
        if(a[i][m - 1] != 'A')
        {
            found = false;
        }
        else
            boundary_a_found = true;
    }

    ans_found |= found;
    found = true;

    for(i = 0;i < m;i++)
    {
        if(a[0][i] != 'A')
        {
            found = false;
        }
        else
            boundary_a_found = true;
    }

    ans_found |= found;
    found = true;

    for(i = 0;i < m;i++)
    {
        if(a[n - 1][i] != 'A')
        {
            found = false;
        }
        else
            boundary_a_found = true;
    }

    ans_found |= found;

    if(ans_found)
    {
        cout<<"1\n";
        return;
    }

    if(a[0][0] == 'A' || a[n - 1][0] == 'A'
        || a[n - 1][m - 1] == 'A' || a[0][m - 1] == 'A')
    {
        cout<<"2\n";
        return;
    }

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(a[i][j] != 'A')
                break;
        }

        if(j == m)
        {
            cout<<"2\n";
            return;
        }
    }

    for(j = 0;j < m;j++)
    {
        for(i = 0;i < n;i++)
        {
            if(a[i][j] != 'A')
                break;
        }

        if(i == n)
        {
            cout<<"2\n";
            return;
        }
    }

    if(boundary_a_found)
    {
        cout<<"3\n";
        return;
    }

    cout<<"4\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}