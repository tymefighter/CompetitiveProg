#include<iostream>

using namespace std;

int l[5], s[5], r[5], p[5];

void read()
{
    for(int i = 1;i <= 4;i++)
        cin>>l[i]>>s[i]>>r[i]>>p[i];
}

bool solve()
{
    for(int i = 1;i <= 4;i++)
    {
        if((l[i] || s[i] || r[i]) && p[i])
            return true;
    }

    if((p[1]) && (l[2] || s[3] || r[4]))
        return true;
    
    if((p[2]) && (r[1] || l[3] || s[4]))
        return true;
    
    if((p[3]) && (s[1] || r[2] || l[4]))
        return true;
    
    if((p[4]) && (l[1] || s[2] || r[3]))
        return true;

    
    return false;
}

int main()
{
    read();
    if(solve())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}