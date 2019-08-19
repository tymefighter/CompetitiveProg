#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long long int n;
string s;

void solve()
{
    int par = 0;
    bool flag;
    s.clear();
    for(long long int i = 1;i <= n; i = (i << 1))
    {
        if(n & i)
        {
            par ++;
            s.push_back('1');
        }
        else
            s.push_back('0');
    }

    reverse(s.begin(), s.end());
    cout<<"The parity of "<<s<<" is "<<par<<" (mod 2).\n";
}

int main()
{
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
    }
    return 0;
}