#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>

using namespace std;

stringstream ss;
string s;
int n, m[26], indeg[26];
char remap[26];
vector<vector<int> > a;

void reset()
{
    a.clear();
    a.resize(n);
    
    for(int i = 0;i < n;i++)
        indeg[i] = 0;
}

void read()
{
    n = 0;
    vector<char> alpha_found;

    while(true)
    {
        char u;
        ss >> u;
        if(ss.eof())
            break;
        alpha_found.push_back(u);
    }

    sort(alpha_found.begin(), alpha_found.end());
    for(char u : alpha_found)
    {
        m[u - 'a'] = n;
        remap[n] = u;
        n ++;
    }

    reset();

    getline(cin, s);
    ss.clear();
    ss.str(s);
    while(true)
    {
        char u, v;
        ss >> u >> v;
        if(ss.eof())
            break;
        indeg[m[v - 'a']] ++;
        a[m[u - 'a']].push_back(m[v - 'a']);
    }
}

vector<char> ans;

void Kahn_all_topo()
{
    bool done = true;
    for(int u = 0;u < n;u++)
    {
        if(indeg[u] == 0)
        {
            done = false;
            indeg[u] --;
            ans.push_back(remap[u]);
            for(int v : a[u])
                indeg[v] --;
            
            Kahn_all_topo();

            indeg[u] ++;
            ans.pop_back();
            for(int v : a[u])
                indeg[v] ++;
        }
    }

    if(done)
    {
        for(char x : ans)
            cout<<x;
        cout<<"\n";
    }
}

int main()
{
    int ct = 0;
    while(getline(cin, s))
    {
        if(ct)
            cout<<"\n";
        ss.clear();
        ss.str(s);
        read();
        Kahn_all_topo();
        ct ++;
    }
    return 0;
}