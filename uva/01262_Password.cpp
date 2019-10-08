#include<iostream>
#include<set>

using namespace std;

int k;
char grid[6][5]; // grid represents grid 2
set<char> g[5];  // Set g represents grid 1
set<string> ans;
string pass;

void reset()
{
    for(int i = 0;i < 5;i++)
        g[i].clear();
    ans.clear();
}

void read()
{
    cin>>k;
    int i, j;
    for(i = 0;i < 6;i++)
    {
        for(j = 0;j < 5;j++)
            cin>>grid[i][j];
    }

    for(j = 0;j < 5;j++)
    {
        for(i = 0;i < 6;i++)
            g[j].insert(grid[i][j]);
    }

    for(i = 0;i < 6;i++)
    {
        for(j = 0;j < 5;j++)
            cin>>grid[i][j];
    }
}

void getAns(int c, int r)
{
    if(c == 5)
    {
        ans.insert(pass);
        return;
    }

    if(g[c].find(grid[r][c]) == g[c].end())
        return;

    pass[c] = grid[r][c];

    for(int row = 0;row < 6;row ++)
        getAns(c + 1, row);
}

void solve()
{
    for(int row = 0;row < 6;row ++)
        getAns(0, row);
    
    int no = 1;

    for(string x : ans)
    {
        if(no == k)
        {
            cout<<x<<"\n";
            return;
        }
        no ++;
    }

    cout<<"NO\n";
}

int main()
{
    pass.resize(5);

    int t;
    cin>>t;
    while(t--)
    {
        reset();
        read();
        solve();
    }
    return 0;
}