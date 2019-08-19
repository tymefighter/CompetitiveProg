#include<iostream>
#include<string>

using namespace std;

string s;

void solve()
{
    int x = 0;

    for(char a : s)
        x = (x + (a - '0')) % 10;
    
    x = (10 - x) % 10;
    s.push_back((char)((x + '0')));
    cout<<s<<"\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>s;
        solve();
    }

    return 0;
}