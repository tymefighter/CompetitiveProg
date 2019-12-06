#include<iostream>
#include<algorithm>

using namespace std;



long long int get_value(string s, int i)
{
    if(i != -1)
        s.erase(i, 1);

    long long int val = 0, pw = 1;

    for(char x : s)
    {
        val += (x - '0') * pw;
        pw *= 10;
    }

    return val;
}

void solve()
{
    string s;
    cin>>s;

    reverse(s.begin(), s.end());

    long long int min_val = get_value(s, -1);

    for(int i = 0;i < s.size();i++)
    {
        min_val = min(min_val, get_value(s, i));
    }

    cout<<min_val<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}