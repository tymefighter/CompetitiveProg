#include<iostream>
#include<vector>

using namespace std;

const int N = 105, INF = 100000005;
int n, k, dp[N][N], h[N][N];
vector<vector<pair<int, int> > > h2loc;  // height to location

void read()
{
    cin>>n>>k;
    h2loc.clear();
    h2loc.resize(k);

    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>h[i][j];
            h2loc[h[i][j] - 1].push_back({i, j});
            dp[i][j] = -1;
        }
    }
}

int getAns(int i, int j)
{
    if(h[i][j] == k)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int val = INF;
    for(pair<int, int> x : h2loc[h[i][j]])
        val = min(val, getAns(x.first, x.second) + abs(x.first - i) + abs(x.second - j));

    dp[i][j] = val;
    return val;
}

void solve()
{
    int ans = INF;
    for(pair<int, int> x : h2loc[0])
        ans = min(ans, getAns(x.first, x.second));
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}