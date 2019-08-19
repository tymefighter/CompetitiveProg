#include<iostream>

using namespace std;

char a[505][505];
bool shape[505][505];
int h, w;

void read()
{
    cin>>h>>w;

    int i, j;
    for(i = 0;i < h;i++)
    {
        for(j = 0;j < w;j++)
        {
            cin>>a[i][j];
            shape[i][j] = false;
        }
    }
}

bool is_centre(int r, int c)
{
    if(a[r][c] == '*' && a[r-1][c] == '*' && a[r+1][c] == '*' && a[r][c-1] == '*' && a[r][c+1] == '*')
        return true;
    else
        return false;
}

bool solve()
{
    int cr, cc; //centre coords
    int r, c;

    cr = cc = -1;
    for(r = 1;r < h - 1;r++)
    {
        for(c = 1;c < w - 1;c++)
        {
            if(is_centre(r, c))
            {
                cr = r, cc = c;
                shape[cr][cc] = true;
                break;
            }
        }
    }

    if(cr == -1)    // no centre
        return false;
    
    r = cr - 1, c = cc;
    while(r >= 0 && a[r][c] == '*')
    {
        shape[r][c] = true;
        r--;
    }

    r = cr + 1, c = cc;
    while(r < h && a[r][c] == '*')
    {
        shape[r][c] = true;
        r++;
    }

    r = cr, c = cc - 1;
    while(c >= 0 && a[r][c] == '*')
    {
        shape[r][c] = true;
        c--;
    }

    r = cr, c = cc + 1;
    while(c < w && a[r][c] == '*')
    {
        shape[r][c] = true;
        c++;
    }


    for(r = 0;r < h;r++)
    {
        for(c = 0;c < w;c++)
        {
            if(!shape[r][c] && a[r][c] == '*')
                return false;
        }
    }

    return true;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}