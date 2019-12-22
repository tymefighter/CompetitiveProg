#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

class Box
{
    public:
    int idx, d[15];
};

const int K = 35;
int k, n, dp[K], p[K];
Box box[K];

bool vis[K];
vector<int> topo;


bool isLess(int u, int v)
{
    for(int i = 0;i < n;i++)
    {
        if(box[u].d[i] >= box[v].d[i])
            return false;
    }
    return true;
}

void dfs_t_sort(int i)
{
    vis[i] = true;
    for(int j = 0;j < k;j++)
    {
        if(!vis[j] & isLess(i, j))
            dfs_t_sort(j);
    }

    topo.push_back(i);
}

void read()
{
    int i, j;
    for(i = 0;i < k;i++)
    {
        box[i].idx = i + 1;
        for(j = 0;j < n;j++)
            cin>>box[i].d[j];
        
        sort(box[i].d, box[i].d + n);
    }

    topo.clear();
    for(i = 0;i < k;i++)
        vis[i] = false;
    
    for(i = 0;i < k;i++)
    {
        if(!vis[i])
            dfs_t_sort(i);
    }

    assert(topo.size() == k);
    reverse(topo.begin(), topo.end());
}

void printSoln(int v)
{
    if(p[v] == -1)
    {
        cout<<box[topo[v]].idx;
        return;
    }
    
    printSoln(p[v]);
    cout<<" "<<box[topo[v]].idx;
}

void solve()
{
    int i, j;
    for(i = 0;i < k;i++)
    {
        dp[i] = 1;
        p[i] = -1;

        for(j = 0;j < i;j++)
        {
            if(isLess(topo[j], topo[i]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans_idx = 0;
    for(i = 1;i < k;i++)
    {
        if(dp[i] > dp[ans_idx])
            ans_idx = i;
    }

    cout<<dp[ans_idx]<<"\n";
    printSoln(ans_idx);
    cout<<"\n";
}

int main()
{
    while(cin>>k>>n)
    {
        read();
        solve();
    }
    return 0;
}