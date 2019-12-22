#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 105;
int n, k, dp[N][N];
vector<pair<int, pair<int, int> > > topo;

void read()
{
    topo.clear();
    int i, j, money_val;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin>>money_val;

            dp[i][j] = -1; 
            if(i == j && j == 0)
                dp[0][0] = money_val;
            topo.push_back({money_val, {i, j}});
        }
    }

    sort(topo.begin(), topo.end());
}

bool jumpIsAllowed(int i, int j)
{
    if(topo[j].first == topo[i].first)
        return false;

    if(abs(topo[j].second.first - topo[i].second.first) <= k 
        && topo[j].second.second == topo[i].second.second)
        return true;
    
    if(abs(topo[j].second.second - topo[i].second.second) <= k 
        && topo[j].second.first == topo[i].second.first)
        return true;
    
    return false;
}

void solve()
{
    int i, j, ans_val = -1;
    
    for(i = 0;i < topo.size();i++)
    {
        if(dp[topo[i].second.first][topo[i].second.second] == -1)
            continue;

        ans_val = max(ans_val, dp[topo[i].second.first][topo[i].second.second]);
        for(j = i + 1;j < topo.size();j++)
        {
            if(jumpIsAllowed(i, j))
                dp[topo[j].second.first][topo[j].second.second] = max(dp[topo[j].second.first][topo[j].second.second], dp[topo[i].second.first][topo[i].second.second] + topo[j].first);
        }
    }

    cout<<ans_val<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        cin>>n>>k;
        read();
        solve();
    }
    return 0;
}