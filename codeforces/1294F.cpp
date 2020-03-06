#include<iostream>
#include<vector>
#include<algorithm>

/*
    Not solved yet....
*/

using namespace std;

const int N = 200005;
int n;
vector<vector<int> > a;
int dp[N], lp[N], lp_node[N];
pair<int, int> dp_ans[N];
// dp[i]: Maximum number of distinct edges we can
// get if a = i and we look for b and c in ith subtree
// dp_ans[i]: {b, c} where b and c are optimal values for dp[i]
// lp[i]: Length of longest path from ith vert into it's subtree
// lp_node[i]: x where x is the node to which is a longest path from i

void read()
{
    cin>>n;
    a.clear();
    a.resize(n);
    int u, v;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v;
        u --, v --;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void solve(int u, int par)
{
    int g, h = -1;
    pair<int, int> g_ans = {-1, -1}, h_ans;
    // g: maximum value we can acquire if we assume that path to
    // b and c have some edge in common
    // h: maximum value we can acquire if we assume that path to
    // b and c have no edge in commong
    vector<pair<int, int> > long_paths; // (x, y): x is the value, y is the vert

    for(int v : a[u])
    {
        if(v != par)
        {
            solve(v, u);
            long_paths.push_back({lp[v], lp_node[v]});
            if(g_ans.first == -1 || g < 1 + dp[v])
            {
                g = 1 + dp[v];
                g_ans = dp_ans[v];
            }
        }
    }

    if(long_paths.size() == 0)
    {
        lp[u] = 0;
        lp_node[u] = u;
        dp[u] = 0;
        dp_ans[u] = {u, u};
        return;
    }

    sort(long_paths.begin(), long_paths.end());
    reverse(long_paths.begin(), long_paths.end());
    lp[u] = long_paths[0].first + 1;
    lp_node[u] = long_paths[0].second;

    if(long_paths.size() >= 2)
    {
        h = long_paths[0].first + long_paths[1].first + 2;
        h_ans = {long_paths[0].second, long_paths[1].second};
    }

    if(g >= h)
    {
        dp[u] = g;
        dp_ans[u] = g_ans;
    }
    else
    {
        dp[u] = h;
        dp_ans[u] = h_ans;
    }
}

int main()
{
    read();
    solve(0, -1);

    int a = 0, b, c;
    for(int i = 1;i < n;i++)
    {
        if(dp[i] > dp[a])
            a = i;
    }
    b = dp_ans[a].first;
    c = dp_ans[a].second;
    if(c == b)
    {
        for(int i = 0;i < n;i++)
        {
            if(a != i && b != i)
            {
                c = i;
                break;
            }
        }
    }
    cout<<dp[a]<<"\n";
    cout<<a + 1<<" "<<b + 1<<" "<<c + 1<<"\n";

    return 0;
}