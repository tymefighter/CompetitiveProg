#include<iostream>
#include<string>

using namespace std;

string s;

void solve()
{

    int n = 0;

    for(char x : s)
    {
        if(x == '1')
            n++;
    }

    if(n % 2)
        cout<<"WIN\n";
    else
        cout<<"LOSE\n";
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