#include<iostream>
#include<string>

using namespace std;

int m;
string h[10], s;

void read()
{
    for(int i = 0;i < 10;i++)
        cin>>h[i];
    m = h[0].size() - 2;
    
    s.clear();
    s.resize(m);
}

void solve()
{
    int i, j;
    int val, pw;

    for(j = 1;j <= m;j++)
    {
        val = 0, pw = 1;
        for(i = 1;i <= 8;i++)
        {
            if(h[i][j] == '\\')
                val += pw;
            pw *= 2;
        }
        s[j - 1] = (char)val;
    }

    cout<<s<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}