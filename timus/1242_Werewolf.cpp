#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


const int MAX_SIZE = 1005, G = 0, GREV = 1;;
char line[128];

int n;
vector<vector<int> > a[2];
bool visited[MAX_SIZE], des[MAX_SIZE], anc[MAX_SIZE];
bool eliminated[MAX_SIZE];

void reset()
{
    a[G].resize(n);
    a[GREV].resize(n);
    
    for(int i = 0;i < n;i++)
        eliminated[i] = des[i] = anc[i] = false;
}

void read()
{
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &n);
    reset();

    int u, v;
    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if(strcmp(line, "BLOOD\n") == 0)
            break;
        
        sscanf(line, "%d %d", &u, &v);
        u --, v --;
        a[G][v].push_back(u);
        a[GREV][u].push_back(v);
    }

    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        sscanf(line, "%d", &u);
        u --;
        anc[u] = des[u] = eliminated[u] = true;
    }
}

void reset_vis()
{
    for(int i = 0;i < n;i++)
        visited[i] = false;
}

bool dfs(int u, int gtype)
{
    visited[u] = true;

    for(int i = 0;i < a[gtype][u].size();i++)
    {
        int v = a[gtype][u][i];
        if(gtype == G)
            des[u] |= dfs(v, gtype);
        else
            anc[u] |= dfs(v, gtype);
    }

    if(gtype == G)
        return des[u];
    else
        return anc[u];
}

void solve()
{
    for(int gtype = 0;gtype < 2;gtype ++)
    {
        reset_vis();
        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
                (void)dfs(i, gtype);
        }
    }

    bool found_a_suspect = false;
    for(int i = 0;i < n;i++)
    {
        if(!(anc[i] | des[i]))
        {
            cout<<i + 1<<" ";
            found_a_suspect = true;
        }
    }
    if(!found_a_suspect)
        cout<<"0";
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}