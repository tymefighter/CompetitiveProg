#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int n, m;
vector<string> all, a, del;
set<int> s;

void reset()
{
    all.clear();
    all.resize(n);
    a.clear();
    del.clear();
    s.clear();
}

void read()
{
    int i, x;
    cin>>n>>m;

    reset();

    for(i = 0;i < n;i++)
        cin>>all[i];

    for(i = 0;i < m;i++)
    {
        cin>>x;
        x--;
        s.insert(x);
    }


    for(i = 0;i < n;i++)
    {
        if(s.find(i) == s.end())
            a.push_back(all[i]);
        else
            del.push_back(all[i]);
    }
}

string st;

bool solve()
{
    int i, j;
    st = del[0];
    for(i = 1;i < del.size();i++)
    {
        if(st.size() != del[i].size())
            return false;

        for(j = 0;j < st.size();j++)
        {
            if(st[j] != '?' && st[j] != del[i][j])
                st[j] = '?';
        }
    }

    for(i = 0;i < a.size();i++)
    {
        if(st.size() != a[i].size())
            continue;
        
        for(j = 0;j < st.size();j++)
        {
            if(!(st[j] == '?' || st[j] == a[i][j]))
                break;
        }

        if(j == st.size())
            return false;
    }

    return true;
}

int main()
{
    read();
    if(solve())
        cout<<"Yes\n"<<st<<"\n";
    else
        cout<<"No\n";
    return 0;
}