#include<iostream>
#include<string>
#include<sstream>

using namespace std;

stringstream ss;
string s;
int n;
int a[105];

int gcd(int a, int b)
{
    // b >= a
    return (a == 0 ? b : gcd(b % a, a));
}

void read()
{
    int i = 0;
    while(!ss.eof())
    {
        ss >> a[i];
        i++;
    }
    n = i;
}

void solve()
{
    int max_val = 0, i, j;
    for(i = 0;i < n;i++)
    {
        for(j = i + 1;j < n;j++)
            max_val = max(max_val, gcd(a[i], a[j]));
    }
    cout<<max_val<<"\n";
}

int main()
{
    int t;
    getline(cin, s);
    ss.clear();
    ss.str(s);
    ss >> t;

    while(t--)
    {
        getline(cin, s);
        while(s[s.size() - 1] == ' ')
            s.pop_back();
        ss.clear();
        ss.str(s);
        read();
        solve();
    }
    return 0;
}