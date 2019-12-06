#include<iostream>

using namespace std;

int n;
bool a[2][200005];


void read()
{
    cin>>n;
    int i, j;
    char c;
    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>c;
            if(c <= '2')
                a[i][j] = true;
            else
                a[i][j] = false;
        }
    }
}

bool solve()
{
    int i = 0, j = 0;

    while(j < n)
    {
        if(a[i][j])
            j ++;
        else
        {
            if(a[1 - i][j])
                return false;
            i = 1 - i;
            j ++;
        }
    }

    if(i == 1)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}