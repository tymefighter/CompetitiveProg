#include<iostream>
#include<cstdio>

using namespace std;

bool format;
char a[201][201];
int m, n;
int num_ch;


void read()
{
    cin>>m>>n;

    if(format)
    {
        int i, j;
        for(i = 0;i < m;i++)
        {
            for(j = 0;j < n;j++)
                cin>>a[i][j];
        }
    }
}

void printAns()
{
    int i, j;
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(num_ch != 0 && num_ch % 50 == 0)
                cout<<"\n";
            cout<<a[i][j];
            num_ch++;
        }
    }
}

int check(int r1, int r2, int c1, int c2)
{
    int i, j;
    bool flag1, flag2;
    flag1 = flag2 = false;

    for(i = r1;i <= r2;i++)
    {
        for(j = c1;j <= c2;j++)
        {
            if(a[i][j] == '1')
                flag1 = true;
            else
                flag2 = true;
        }
    }

    if(flag1 && flag2)
        return -1;
    else if(flag1)
        return 1;
    else
        return 0;
}

void solve1(int r1, int r2, int c1, int c2)
{
    if(r1 > r2 || c1 > c2)
        return;

    if(r1 == r2 && c1 == c2)
    {
        if(num_ch != 0 && num_ch % 50 == 0)
            cout<<"\n";
        cout<<a[r1][c1];
        num_ch++;
        return;
    }

    int val = check(r1, r2, c1, c2);
    if(val != -1)
    {
        if(num_ch != 0 && num_ch % 50 == 0)
            cout<<"\n";
        cout<<val;
        num_ch++;
        return;
    }


    if(num_ch != 0 && num_ch % 50 == 0)
        cout<<"\n";
    cout<<'D';
    num_ch++;

    int rmid = (r1 + r2) / 2, cmid = (c1 + c2) / 2;
    solve1(r1, rmid, c1, cmid);
    solve1(r1, rmid, cmid + 1, c2);
    solve1(rmid + 1, r2, c1, cmid);
    solve1(rmid + 1, r2, cmid + 1, c2);
}

void solve2(int r1, int r2, int c1, int c2)
{
    char val;
    cin>>val;

    if(val != 'D')
    {
        int i, j;
        for(i = r1;i <= r2;i++)
        {
            for(j = c1;j <= c2;j++)
            {
                a[i][j] = val;
            }
        }
        return;
    }

    int rmid = (r1 + r2) / 2, cmid = (c1 + c2) / 2;

    if(r1 == r2)
    {
        solve2(r1, rmid, c1, cmid);
        solve2(r1, rmid, cmid + 1, c2);
        return;
    }
    else if(c1 == c2)
    {
        solve2(r1, rmid, c1, cmid);
        solve2(rmid + 1, r2, c1, cmid);
        return;
    }


    solve2(r1, rmid, c1, cmid);
    solve2(r1, rmid, cmid + 1, c2);
    solve2(rmid + 1, r2, c1, cmid);
    solve2(rmid + 1, r2, cmid + 1, c2);
    return;
}

int main()
{
    char c;

    while(cin>>c)
    {
        if(c == '#')
            break;
        format = (c == 'B' ? true : false);
        read();

        c = (c == 'B' ? 'D' : 'B');
        printf("%c%4d%4d\n", c, m, n);

        num_ch = 0;

        if(format)
            solve1(0, m-1, 0, n-1);
        else
        {
            solve2(0, m-1, 0, n-1);
            printAns();
        }
        
        cout<<"\n";
    }
    return 0;
}