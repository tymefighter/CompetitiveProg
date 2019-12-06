#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n, m;
vector<vector<char> > a;
vector<vector<int> > distStart, distEnd;
map<int, int> nodeDistCount;

void reset()
{
    a.clear();
    a.assign(n, vector<char> (m));
    distStart.clear();
    distStart.assign(n, vector<int> (m));
    distEnd.clear();
    distEnd.assign(n, vector<int> (m));
    nodeDistCount.clear();

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            distStart[i][j] = distEnd[i][j] = -1;
    }
}

void read()
{
    cin>>n>>m;
    reset();
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            cin>>a[i][j];
    }
}

void dfs(int r, int c, bool isRev)
{   
    if(!isRev)
    {
        if(r + 1 < n && a[r + 1][c] == '.' && distStart[r + 1][c] == -1)
        {
            distStart[r + 1][c] = distStart[r][c] + 1;
            dfs(r + 1, c, false);
        }

        if(c + 1 < m && a[r][c + 1] == '.' && distStart[r][c + 1] == -1)
        {
            distStart[r][c + 1] = distStart[r][c] + 1;
            dfs(r, c + 1, false);
        }
    }
    else
    {
        if(r - 1 >= 0 && a[r - 1][c] == '.' && distEnd[r - 1][c] == -1)
        {
            distEnd[r - 1][c] = distEnd[r][c] + 1;
            dfs(r - 1, c, true);
        } 
        if(c - 1 >= 0 && a[r][c - 1] == '.' && distEnd[r][c - 1] == -1)
        {
            distEnd[r][c - 1] = distEnd[r][c] + 1;
            dfs(r, c - 1, true);
        }
    }
}

void solve()
{
    distStart[0][0] = 0;
    dfs(0, 0, false);

    if(distStart[n - 1][m - 1] == -1)
    {
        cout<<"0\n";
        return;
    }

    distEnd[n - 1][m - 1] = 0;
    dfs(n - 1, m - 1, true);

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if((i == 0 && j == 0)
                || (i == n - 1 && j == m - 1))
                    continue;
                
            if(distStart[i][j] != -1 && distEnd[i][j] != -1)    // If node lies on a path from (0, 0) to (n - 1, m - 1), then increment the count of it's distance
                nodeDistCount[distStart[i][j]] ++;
        }
    }

    for(auto x : nodeDistCount)
    {
        if(x.second == 1) // If there is only one node with the distance x.first, then we may place a block on this node
        {
            cout<<"1\n";
            return;
        } 
    }

    cout<<"2\n";
}

int main()
{
    read();
    solve();
    return 0;
}