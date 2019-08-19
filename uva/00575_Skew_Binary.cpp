#include<iostream>
#include<string>

using namespace std;

string s;

void solve()
{
    int ans = 0, power = 2;
    for(int i = s.size() - 1;i >= 0;i--)
    {
        ans += (int)(s[i] - '0') * (power - 1);
        power *= 2;
    }

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>s)
    {
        if(s == "0")
            break;
        solve();
    }
    return 0;
}