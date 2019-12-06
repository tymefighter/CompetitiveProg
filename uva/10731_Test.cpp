#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 26;

int m;
vector<vector<int> > a, a_rev;
vector<int> topo;
bool vis[N], seen_in_input[N];
int ct, scc[N], repr_char_scc[N];
pair<char, char> scc_in_character[N];

void resetVis()
{
    for(int i = 0;i < N;i++)
        vis[i] = false;
}

void reset()
{
    a.clear();
    a.resize(N);
    a_rev.clear();
    a_rev.resize(N);
    topo.clear();
    ct = 0;
    for(int i = 0;i < N;i++)
    {
        seen_in_input[i] = false;
        scc[i] = -1;
        repr_char_scc[i] = '\0';
    }
}

void read()
{
    static int choice[5] = {0};
    int chosen;

    int i, j;
    char c;
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < 5;j++)
        {
            cin>>c;
            choice[j] = c - 'A';
            seen_in_input[choice[j]] = true;
        }
        cin>>c;
        chosen = c - 'A';

        for(j = 0;j < 5;j++)
        {
            if(choice[j] == chosen)
                continue;
            a[chosen].push_back(choice[j]);
            a_rev[choice[j]].push_back(chosen);
        }
    }
}

void dfs_t_sort(int u)
{
    vis[u] = true;
    for(int v : a[u])
    {
        if(!vis[v])
            dfs_t_sort(v);
    }
    topo.push_back(u);
}

void dfs_scc(int u)
{
    vis[u] = true;
    scc[u] = ct;
    for(int v : a_rev[u])
    {
        if(!vis[v])
            dfs_scc(v);
    }
}

void solve()
{
    resetVis();
    for(int i = 0;i < N;i++)
    {
        if(seen_in_input[i] && !vis[i])
            dfs_t_sort(i);
    }
    reverse(topo.begin(), topo.end());
    
    resetVis();
    for(int x : topo)
    {
        if(!vis[x])
        {
            dfs_scc(x);
            ct ++;
        }
    }

    for(int i = 0;i < N;i++)
    {
        if(seen_in_input[i])
        {
            if(repr_char_scc[scc[i]] == '\0')
                repr_char_scc[scc[i]] = 'A' + i;
            
            scc_in_character[i] = {repr_char_scc[scc[i]], 'A' + i};
        }
        else
            scc_in_character[i] = {'Z' + 1, 'A' + i};
    }

    sort(scc_in_character, scc_in_character + N);
    
    char prev = scc_in_character[0].first;
    cout<<scc_in_character[0].second;

    for(int i = 1;i < N;i++)
    {
        if(scc_in_character[i].first == 'Z' + 1)
            break;
        
        if(scc_in_character[i].first == prev)
            cout<<" "<<scc_in_character[i].second;
        else
        {
            prev = scc_in_character[i].first;
            cout<<"\n"<<scc_in_character[i].second;
        }
    }
    cout<<"\n";
}

int main()
{
    int ct = 0;
    while(cin>>m)
    {
        if(!m)
            break;
        if(ct)
            cout<<"\n";
        reset();
        read();
        solve();
        ct ++;
    }
    return 0;
}