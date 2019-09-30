#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, q;
vector<string> a;
set<string> dict;
string s;

void read()
{
    cin>>n;
    a.resize(n);
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        dict.insert(a[i]);
    }
}

bool check(int idx)
{
    string x = a[idx];
    if(abs((int)(s.size() - x.size())) >= 2)
        return false;
    
    if(s.size() == x.size())
    {
        int i, j, diff = 0;
        for(i = 0;i < s.size();i++)
        {
            if(s[i] != x[i])
                diff ++;
            if(diff > 1)
                break;
        }
        if(diff == 1)
            return true;
        
        for(i = 0;i < s.size() - 1;i++)
        {
            swap(s[i], s[i + 1]);
            if(s == x)
            {
                swap(s[i], s[i + 1]);
                return true;
            }
            swap(s[i], s[i + 1]);
        }
    }

    string r;
    for(int i = 0;i < s.size();i++)
    {
        r = s;
        r.erase(i, 1);
        if(r == x)
            return true;
    }

    for(int i = 0;i < x.size();i++)
    {
        r = x;
        r.erase(i, 1);
        if(s == r)
            return true;
    }
    return false;
}

void solve()
{
    if(dict.find(s) != dict.end())
    {
        cout<<s<<" is correct\n";
        return;
    }

    for(int i = 0;i < a.size();i++)
    {
        if(check(i))
        {
            cout<<s<<" is a misspelling of "<<a[i]<<"\n";
            return;
        }
    }

    cout<<s<<" is unknown\n";
}

int main()
{
    read();
    cin>>q;
    while(q--)
    {
        cin>>s;
        solve();
    }
    return 0;
}