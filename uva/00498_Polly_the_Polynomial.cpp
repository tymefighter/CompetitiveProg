#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string s;
stringstream ss;
int n;
vector<int> c;

long long int eval(int x)
{
    long long int ans = 0;
    long long int xp = 1;
    for(int i = 0;i < n;i++)
    {
        ans += c[n - i - 1] * xp;
        xp *= x;
    }

    return ans;
}

void solve()
{
    int x;
    c.clear();
    ss.clear();
    ss.str(s);

    while(!ss.eof())
    {
        ss >> x;
        c.push_back(x);
    }
    n = c.size();

    getline(cin, s);
    ss.clear();
    ss.str(s);

    int ct = 0;

    while(!ss.eof())
    {
        if(ct)
            cout<<" ";
        ss >> x;
        cout<<eval(x);
        ct++;
    }
    cout<<"\n";
}

int main()
{
    while(getline(cin, s))
        solve();
    return 0;
}