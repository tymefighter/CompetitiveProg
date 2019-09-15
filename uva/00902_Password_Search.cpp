#include<iostream>
#include<map>

using namespace std;

string s;
int n;
map<string, int> m;

void solve()
{
    m.clear();
    int i, j, max_val = 0;
    string a;

    a.resize(n);
    for(i = 0;i <= s.size() - n; i++)
    {
        for(j = 0;j < n;j++)
            a[j] = s[i + j];
        m[a] ++;
    }

    for(auto p : m)
    {
        if(p.second > max_val)
        {
            max_val = p.second;
            a = p.first;
        }
    }

    cout<<a<<"\n";
}

int main()
{
    while(cin>>n>>s)
        solve();
    return 0;
}