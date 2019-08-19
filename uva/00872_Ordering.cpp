#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

string s;
int n;
stringstream ss;
map<char, int> m;
vector<char> remap;
vector<vector<int> > adj;
vector<int> indeg;
vector<int> ans;

void clearAll()
{
    remap.clear();
    s.clear();
    ss.str("");
    ss.clear();
    m.clear();
    indeg.clear();
    ans.clear();
    adj.clear();
}

void read()
{
    char a, b;
    bool flag;
    int ct = 0;

    getline(cin, s);
    ss.str(s);

    while(!ss.eof())
    {
        ss >> a;
        if(ss.eof())
            break;

        remap.push_back(a);
    }

    sort(remap.begin(), remap.end());

    for(int i = 0;i < remap.size();i++)
    {
        m[remap[i]] = i;
    }

    n = remap.size();
    ss.clear();
    adj.resize(n);
    indeg.assign(n, 0);

    getline(cin, s);
    flag = false;

    ss.str(s);

    while(!ss.eof())
    {
        if(!flag)
        {
            ss >> a;
            if(ss.eof())
                break;
            flag = true;
        }
        else
        {
            ss >> b;
            if(b != '<')
            {
                flag = false;
                indeg[m[b]]++;
                adj[m[a]].push_back(m[b]);
            }
        }
    }
}

void printAns()
{
    if(ans.size() != n)
    {
        cout<<"NO\n";
        return;
    }
    for(int i = 0;i < ans.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<remap[ans[i]];
    }
    cout<<"\n";
}

void Kahn()
{
    bool flag = true;

    for(int i = 0;i < n;i++)
    {
        if(indeg[i] == 0)
        {
            indeg[i]--;
            ans.push_back(i);

            for(int v : adj[i])
                indeg[v]--;

            Kahn();

            indeg[i]++;
            ans.pop_back();

            for(int v : adj[i])
                indeg[v]++;

            flag = false;
        }
    }

    if(flag)
    {
        printAns();
    }
}

int main()
{
    int t;
    getline(cin, s);
    t = stoi(s);

    for(int i = 0;i < t;i++)
    {
        if(i)
            cout<<"\n";
        clearAll();
        getline(cin, s);
        read();
        Kahn();
    }

    return 0;
}