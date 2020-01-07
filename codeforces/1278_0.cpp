#include<iostream>

using namespace std;

string p, h;
int lctp[26], lcth[26];

bool checkEquals()
{
    for(int i = 0;i < 26;i++)
    {
        if(lctp[i] != lcth[i])
            return false;
    }
    return true;
}

bool solve()
{
    if(p.size() > h.size())
        return false;

    int i;
    for(i = 0;i < 26;i++)
        lcth[i] = lctp[i] = 0;

    for(i = 0;i < p.size();i++)
    {
        lctp[p[i] - 'a'] ++;
        lcth[h[i] - 'a'] ++;
    }   

    if(checkEquals())
        return true;

    for(;i < h.size();i++)
    {
        lcth[h[i - p.size()] - 'a'] --;
        lcth[h[i] - 'a'] ++;
        if(checkEquals())
            return true;
    }

    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>p;
        cin>>h;
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}