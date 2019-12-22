#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int> > a;
vector<string> arr_str;
vector<int> topo;
int m[26];
char remap[26];
bool vis[26];

void reset()
{
    arr_str.clear();
    a.clear();
    topo.clear();
    n = 0;

    for(int i = 0;i < 26;i++)
        m[i] = -1;
}

string s;

bool read()
{
    bool saw_input = false;
    
    int max_string_size = 0;
    reset();
    while(cin>>s)
    {
        if(s == "#")
        {
            saw_input = true;
            break;
        }

        arr_str.push_back(s);
        max_string_size = max(max_string_size, (int)s.size());
        for(char x : s)
        {
            if(m[x - 'A'] == -1)
            {
                m[x - 'A'] = n;
                remap[n] = x;
                n ++;
            }
        }
    }
    
    if(!saw_input)
        return false;

    a.resize(n);

    for(int i = 1;i < arr_str.size();i++)
    {
        for(int j = 0;j < arr_str[i].size();j++)
        {
            if(j >= arr_str[i - 1].size())
                break;
            
            if(arr_str[i - 1][j] != arr_str[i][j])
            {
                a[m[arr_str[i - 1][j] - 'A']].push_back(m[arr_str[i][j] - 'A']);
                break;
            }
        }
    }

    return true;
}

void dfs(int u)
{
    vis[u] = true;

    for(int v : a[u])
    {
        if(!vis[v])
            dfs(v);
    }

    topo.push_back(u);
}

void t_sort()
{
    for(int i = 0;i < n;i++)
        vis[i] = false;

    for(int i = 0;i < n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    reverse(topo.begin(), topo.end());
    for(int x : topo)
        cout<<remap[x];
    cout<<"\n";
}

int main()
{
    while(read())
        t_sort();
    return 0;
}