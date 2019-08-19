#include<iostream>
#include<algorithm>

using namespace std;

const int MOD = 131071;
int idx, n;
char s[100005], x;

void read()
{
    while(cin>>x)
    {
        if(x == '#')
            break;
        s[idx++] = x;
    }

    n = idx;
    reverse(s, s + n);
}

void solve()
{
    int ans = 0;
    int pw = 1;

    for(int i = 0;i < n;i++)
    {
        if(s[i] == '1')
            ans = (ans + pw) % MOD;
        pw = (pw * 2) % MOD;
    }

    if(ans == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    while(cin>>x)
    {
        idx = 0;
        s[idx++] = x;
        read();
        solve();
    }
    return 0;
}