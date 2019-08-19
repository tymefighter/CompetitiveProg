#include<iostream>

using namespace std;

char a[4][4];

void read()
{
    int i, j;
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
            cin>>a[i][j];
    }
}

char solve(char c)
{
    int i, j;
    char ret = 'd';
    bool won = false, draw = false;

    for(i = 0;i < 4;i++)
    {
        won = true;
        for(j = 1;j < 4;j++)
        {
            if(a[i][j] != a[i][j - 1] || a[i][j] == '.')
            {
                won = false;
                break;
            }
        }

        if(won)
            return a[i][0];
    }

    for(j = 0;j < 4;j++)
    {
        won = true;
        for(i = 1;i < 4;i++)
        {
            // cout<<j<<" "<<i<<"-\n";
            if(a[i][j] != a[i - 1][j] || a[i][j] == '.')
            {
                // cout<<i<<" "<<j<<" -- "<<a[i][j]<<" "<<a[i - 1][j]<<"--\n";
                won = false;
                break;
            }
        }

        if(won)
            return a[0][j];
    }

    // cout<<"\n\n";

    won = true;
    for(i = 1;i < 4;i++)
    {
        if(a[i][i] != a[i - 1][i - 1] || a[i][i] == '.')
        {
            won = false;
            break;
        }
    }
    if(won)
        return a[0][0];


    won = true;
    for(i = 1;i < 4;i++)
    {
        if(a[i][3 - i] != a[i - 1][4 - i] || a[i][3 - i] == '.')
        {
            won = false;
            break;
        }
    }
    if(won)
        return a[0][3];
    
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            if(a[i][j] == '.')
            {
                a[i][j] = c;
                if(c == 'x')
                {
                    ret = solve('o');
                    if(ret == 'd')
                        draw = true;
                    if(ret == 'x')
                    {
                        a[i][j] = '.';
                        return 'x';
                    }
                }
                else
                {
                    ret = solve('x');
                    if(ret == draw)
                        draw = true;
                    if(ret == 'o')
                    {
                        a[i][j] = '.';
                        return 'o';
                    }
                }
                a[i][j] = '.';
            }
        }
    }

    if(draw)
        return 'd';
    else
    {
        if(c == 'x')
            return 'o';
        else
            return 'x';
    }
}

void solve2()
{
    int i, j;
    char ret;
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            ret = '0';
            if(a[i][j] == '.')
            {
                a[i][j] = 'x';
                ret = solve('o');
                a[i][j] = '.';

                if(ret == 'x')
                {
                    printf("(%d,%d)\n", i, j);
                    return;
                }
            }
        }
    }

    printf("#####\n");
}

int main()
{
    char ch;
    while(cin>>ch)
    {
        if(ch == '$')
            break;
        read();
        solve2();
    }
    
    return 0;
}