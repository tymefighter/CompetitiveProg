#include<iostream>

using namespace std;
const int INF = 100000000;
int start, nlow, nhigh, n, m;
string a[55], s;

void get_bound()
{
    int val = 0;
    char prev = '\0';
    start = 0;
    nlow = INF;
    nhigh = -INF;
    m = s.size();

    for(char c : s)
    {
        if(c == 'R')
        {
            if(prev == 'R')
                val ++;
        }
        else if(c == 'C')
        {
            if(prev == 'R')
                val ++;
        }
        else
        {
            if(prev == 'F' || prev == 'C')
                val --;
        }
        
        nlow = min(nlow, val);
        nhigh = max(nhigh, val);
        prev = c;
    }

    n = nhigh - nlow + 1;
    start = 1 - nlow;
    // cout<<nlow<<" "<<nhigh<<"\n";
}

void format_output()
{
    int i;
    for(i = 0;i <= n + 1;i++)
    {
        a[i].clear();
        a[i].assign(m + 3, ' ');
    }

    a[0][0] = '+';

    for(i = 1;i <= m + 2;i++)
        a[0][i] = '-';
    
    for(i = 1;i <= n + 1;i++)
        a[i][0] = '|';
}

void reverse_output()
{
    int i, j;

    for(j = 0;j < a[0].size();j++)
    {
        for(i = 0;i < (n + 1) / 2;i++)
            swap(a[i][j], a[n + 1 - i - 1][j]);
    }
}

void solve(bool pr_flag)
{
    int x = 2, y = start;
    char prev = '\0';
    for(char c : s)
    {
        if(c == 'R')
        {
            if(prev == 'R')
                y ++;
            a[y][x] = '/';
        }
        else if(c == 'C')
        {
            if(prev == 'R')
                y ++;
            
            a[y][x] = '_';
        }
        else
        {
            if(prev == 'F' || prev == 'C')
                y --;

            a[y][x] = '\\';
        }
        x ++;
        prev = c;
    }

    reverse_output();
    int i, j = 0, k;
    for(i = 0;i < n + 1;i++)
    {
        for(k = 0;k < a[i].size();k++)
        {
            if(a[i][k] != ' ')
                j = k;
        }

        for(k = 0;k <= j;k++)
            cout<<a[i][k];
        cout<<"\n";
    }
    if(pr_flag)
        cout<<"\n";
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1;i <= t;i++)
    {
        cin>>s;
        printf("Case #%d:\n", i);
        get_bound();
        format_output();
        if(i != t)
            solve(true);
        else
            solve(true);
    }
    return 0;
}