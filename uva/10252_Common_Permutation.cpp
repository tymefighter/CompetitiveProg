#include<iostream>
#include<map>

using namespace std;

map<char, int> m1, m2;
string s;

void read()
{
    m1.clear();
    m2.clear();

    for(char x : s)
        m1[x] ++;
    getline(cin, s);
    for(char x : s)
        m2[x] ++;
}

void solve()
{
    int i;
    string ans;
    for(auto x : m1)
    {
        for(i = 0;i < min(x.second, m2[x.first]);i++)
            ans.push_back(x.first);
    }

    cout<<ans<<"\n";
}

int main()
{
    while(getline(cin, s))
    {
        read();
        solve();
    }
    return 0;
}