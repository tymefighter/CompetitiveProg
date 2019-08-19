#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;

bool solve()
{
    int i, j, n, pow, mod, x, val;
    reverse(s.begin(), s.end());

    cin>>n;
    for(i = 0;i < n;i++)
    {
        cin>>mod;
        pow = 1;
        val = 0;
        for(j = 0;j < s.size();j++)
        {
            x = s[j] - '0';

            val = (val + (pow * x) % mod) % mod;
            pow = (pow * 10) % mod;
        }
        
        if(val != 0)
            break;
    }

    if(i != n)
    {
        i++;
        for(;i < n;i++)
            cin>>mod;
        reverse(s.begin(), s.end());
        return false;
    }

    reverse(s.begin(), s.end());
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>s;
        if(solve())
            cout<<s<<" - "<<"Wonderful.\n";
        else
            cout<<s<<" - "<<"Simple.\n";
    }
    return 0;
}