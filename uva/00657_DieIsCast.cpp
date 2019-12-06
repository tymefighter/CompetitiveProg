#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MX = 55;

int w, h;
bool visited[MX][MX];
char a[MX][MX];

void read()
{
    int i, j;
    for(i = 0;i < h;i++)
    {
        for(j = 0;j < w;j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
        }
    }
}

int ar[] = {-1, 1, 0, 0};
int ac[] = {0, 0, -1, 1};

bool isValid(int r, int c)
{
    if(r < 0 || r >= h || c < 0 || c >= w
        || a[r][c] == '.' || visited[r][c])
        return false;
    return true;
}

void visitDots(int r, int c, vector<pair<int, int> > &nodes_to_visit)
{
    visited[r][c] = true;
    int rd, cd;

    for(int i = 0;i < 4;i++)
    {
        rd = r + ar[i];
        cd = c + ac[i];
        if(isValid(rd, cd))
        {
            if(a[rd][cd] == 'X')
                visitDots(rd, cd, nodes_to_visit);
            else
                nodes_to_visit.push_back({rd, cd});
        }
    }

    return;
}

int dfs(int r, int c)
{
    visited[r][c] = true;
    int val = 0;

    if(a[r][c] == 'X')
    {
        vector<pair<int, int> > nodes_to_visit;
        visitDots(r, c, nodes_to_visit);
        val = 1;

        for(auto coord : nodes_to_visit)
            val += dfs(coord.first, coord.second);
    }
    
    int rd, cd;
    for(int i = 0;i < 4;i++)
    {
        rd = r + ar[i];
        cd = c + ac[i];

        if(isValid(rd, cd))
            val += dfs(rd, cd);
    }

    return val;
}

vector<int> ans;

void solve(int tc)
{
    ans.clear();
    int i, j;

    for(i = 0;i < h;i++)
    {
        for(j = 0;j < w;j++)
        {
            if(isValid(i, j))
                ans.push_back(dfs(i, j));
        }
    }

    sort(ans.begin(), ans.end());
    cout<<"Throw "<<tc<<"\n";

    int no = 0;
    for(auto x : ans)
    {
        if(no)
            cout<<" "<<x;
        else
            cout<<x;
        no ++;
    }
    cout<<"\n\n";
}

int main()
{
    int tc = 1;
    while(cin>>w>>h)
    {
        if(!(w | h))
            break;
        read();
        solve(tc);
        tc ++;
    }
    return 0;
}