#include<iostream>

using namespace std;

char a[101][101];
int n, m, s, ans;
int r, c, dir;

void read()
{

    ans = 0;

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            cin>>a[i][j];
            //cout<<a[i][j];
            if(a[i][j] != '.' && a[i][j] != '*' && a[i][j] != '#')
            {
                if(a[i][j] == 'N')
                    dir = 0;
                else if(a[i][j] == 'L')
                    dir = 1;
                else if(a[i][j] == 'S')
                    dir = 2;
                else if(a[i][j] == 'O')
                    dir = 3;

                r = i, c = j;
                a[r][c] = '.';
            }
        }
        //cout<<"\n";
    }
}

void move()
{
    if(dir == 0 && r > 0 && a[r-1][c] != '#')
    {
        r--;
        if(a[r][c] == '*')
        {
            ans++;
            a[r][c] = '.';
        }
    }
    else if(dir == 1 && c < m-1 && a[r][c+1] != '#')
    {
        c++;
        if(a[r][c] == '*')
        {
            ans++;
            a[r][c] = '.';
        }
    }
    else if(dir == 2 && r < n-1 && a[r+1][c] != '#')
    {
        r++;
        if(a[r][c] == '*')
        {
            ans++;
            a[r][c] = '.';
        }
    }
    else if(dir == 3 && c > 0 && a[r][c-1] != '#')
    {
        c--;
        if(a[r][c] == '*')
        {
            ans++;
            a[r][c] = '.';
        }
    }
}

// 0: up, 1: right, 2: down, 3: left

void traverse()
{
    int i;
    char mv;
    for(i = 0;i < s;i++)
    {
        
        cin>>mv;
        //cout<<mv<<"|"<<dir<<": "<<r<<" "<<c<<" "<<a[r][c]<<" ";
        if(mv == 'D')
            dir = (dir + 1) % 4;
        else if(mv == 'E')
            dir = (dir + 3) % 4;
        else
        {
            move();
        }

        //cout<<r<<" "<<c<<" "<<a[r][c]<<"\n";
    }
}

int main()
{
    while(cin>>n>>m>>s)
    {
        if(! (n | m | s))
            break;
        read();
        traverse();
        cout<<ans<<"\n";
    }

    return 0;
}