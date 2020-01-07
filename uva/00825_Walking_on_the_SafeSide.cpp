#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int n, m;
vector<vector<int> > dp;
vector<vector<bool> > notAllowed;
stringstream ss;
string s;

void reset()
{
    dp.clear();
    dp.assign(n, vector<int>(m));
    notAllowed.clear();
    notAllowed.assign(n, vector<bool>(m));

    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            dp[i][j] = 0;
            notAllowed[i][j] = false;
        }
    }
}

void read()
{
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> n >> m;

    reset();

    int i, r, c, num_inter;

    for(i = 0;i < n;i++)
    {
        getline(cin, s);

        while(s[s.size() - 1] == ' ')
            s.pop_back();

        ss.clear();
        ss.str(s);
        ss >> r;
        r --;
        
        while(!ss.eof())
        {
            ss >> c;
            c --;
            notAllowed[r][c] = true;
        }
    }
}

int ar[] = {1, 0};
int ac[] = {0, 1};

bool isAllowed(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m
        || notAllowed[i][j])
        return false;
    return true;
}

void solve()
{
    dp[0][0] = 1;

    int i, j, k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(notAllowed[i][j])
                continue;
            for(k = 0;k < 2;k++)
            {
                if(isAllowed(i + ar[k], j + ac[k]))
                    dp[i + ar[k]][j + ac[k]] += dp[i][j];
            }
        }
    }

    cout<<dp[n - 1][m - 1]<<"\n";
}

int main()
{
    int t;
    
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> t;

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        getline(cin, s);
        read();
        solve();
    }
    return 0;
}