#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 105;

int n;
map<string, int> city2ind;
vector<string> ind2city;
vector<vector<int> > a;
int ct, dfs_low[N], dfs_num[N];
bool hasCamera[N];

void reset()
{
    city2ind.clear();

    ind2city.clear();
    ind2city.resize(n);

    a.clear();
    a.resize(n);

    ct = 0;
    for(int i = 0;i < n;i++)
    {
        dfs_num[i] = -1;
        hasCamera[i] = false;
    }
}

void read()
{
    for(int i = 0;i < n;i++)
    {
        cin>>ind2city[i];
        city2ind[ind2city[i]] = i;
    }

    int R;
    cin>>R;
    string u, v;

    for(int i = 0;i < R;i++)
    {
        cin>>u>>v;
        a[city2ind[u]].push_back(city2ind[v]);
        a[city2ind[v]].push_back(city2ind[u]);
    }
}

int numCh; // Number of children of the root that were not visited earlier (during the run of the dfs from some other child)

void dfs(int u, int parent)
{
    dfs_num[u] = dfs_low[u] = ct ++;

    for(int v : a[u])
    {
        if(dfs_num[v] == -1)
        {   
            if(parent == -1)
                numCh ++;

            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            if(parent != -1 && dfs_low[v] >= dfs_num[u])        // u should not be the root
                hasCamera[u] = true;
                
        }
        else if(v != parent)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

vector<string> ans;

void solve(int cno)
{
    ans.clear();
    for(int i = 0;i < n;i++)
    {
        if(dfs_num[i] == -1)
        {
            numCh = 0;
            dfs(i, -1);

            if(numCh > 1)
                hasCamera[i] = true;
        }

        if(hasCamera[i])
            ans.push_back(ind2city[i]);
    }
    
    sort(ans.begin(), ans.end());

    if(cno > 1)
        cout<<"\n";
    printf("City map #%d: %lu camera(s) found\n", cno, ans.size());
    for(auto x : ans)
        cout<<x<<"\n";
}

int main()
{
    int cno = 1;
    while(cin>>n)
    {
        if(!n)
            break;
        reset();
        read();
        solve(cno);
        cno ++;
    }
    return 0;
}