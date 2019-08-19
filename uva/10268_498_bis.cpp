#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

string s;
stringstream ss;
int n;
vector<int> c;

long long int eval_der(int x)
{
    long long int ans = 0;
    long long int xp = 1;
    for(int i = 1;i < n;i++)
    {
        ans += i * (c[n - i - 1] * xp);
        xp *= x;
    }

    return ans;
}

void solve()
{
    int x, val;
    ss.clear();
    ss.str(s);
    ss >> val;

    c.clear();
    getline(cin, s);
    ss.clear();
    ss.str(s);

    while(!ss.eof())
    {
        ss >> x;
        c.push_back(x);
    }
    n = c.size();

    cout<<eval_der(val)<<"\n";
}

int main()
{
    while(getline(cin, s))
        solve();
    return 0;
}