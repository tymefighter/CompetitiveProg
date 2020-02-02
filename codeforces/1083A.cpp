#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 300005;
int n;
long long w[N], dp[N];
// dp[i]: Maximum value of gasoline that we can acquire if we start at in the ith
// vertice's subtree and drive to the ith vertex
vector<vector<pair<int, long long> > > a;

void read()
{
    cin>>n;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin>>w[i];

    int u, v, c;
    for(int i = 0;i < n - 1;i++)
    {
        cin>>u>>v>>c;
        u --, v --;
        a[u].push_back({v, (long long)c});
        a[v].push_back({u, (long long)c});
    }
}

long long ans;

void computeDP(int u, int par)
{
    vector<pair<long long, int> > ch;
    for(pair<int, long long> v : a[u])
    {
        if(v.first != par)
        {
            computeDP(v.first, u);
            ch.push_back({dp[v.first] - v.second, v.first});
        }
    }

    if(ch.size() == 0)  // leaf node
    {
        dp[u] = w[u];
        ans = max(ans, dp[u]);
        return;
    }

    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
    dp[u] = max(ch[0].first, 0ll) + w[u];
    ans = max(ans, dp[u]);

    if(ch.size() > 1 && ch[1].first > 0)
        ans = max(ans, ch[0].first + ch[1].first + w[u]);
}

int main()
{
    read();
    ans = 0;
    computeDP(0, -1);
    cout<<ans<<"\n";
    return 0;
}