#include<iostream>
#include<set>

using namespace std;

int m[256];     // map from char to int (corresponding no)
set<int> un;    // un: unusable

void asgn(string s, int val)
{
    for(char x : s)
        m[x] = val;
}

void initPos()
{
    asgn("qaz", 1);
    asgn("wsx", 2);
    asgn("edc", 3);
    asgn("rfvtgb", 4);
    asgn("yhnujm", 7);
    asgn("ik,", 8);
    asgn("ol.", 9);
    asgn("p;/", 10);
}

int n, f;

void read()
{
    int fn;
    un.clear();
    while(f--)
    {
        cin>>fn;
        un.insert(fn);
    }
}

void solve()
{
    set<string> ans;
    string s;
    int i, max_size = 0;

    while(n--)
    {
        cin>>s;
        if(s.size() < max_size)
            continue;
        
        for(i = 0;i < s.size();i++)
        {
            if(un.find(m[s[i]]) != un.end())
                break;
        }

        if(i == s.size())
        {
            if(s.size() > max_size)
            {
                ans.clear();
                max_size = s.size();
            }
            ans.insert(s);
        }
    }

    cout<<ans.size()<<"\n";
    for(auto x : ans)
        cout<<x<<"\n";
}

int main()
{
    initPos();
    while(cin>>f>>n)
    {
        read();
        solve();
    }
    return 0;
}