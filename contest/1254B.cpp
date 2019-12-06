#include<iostream>

using namespace std;

int n, a, b, c;
string s, ans;

void solve()
{
    ans = s;
    int wins = 0;

    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'R')
        {
            if(b > 0)
            {
                ans[i] = 'P';
                b --;
                wins ++;
            }
            else
                ans[i] = '0';
        }
        else if(s[i] == 'P')
        {
            if(c > 0)
            {
                ans[i] = 'S';
                c --;
                wins ++;
            }
            else
                ans[i] = '0';
        }
        else
        {
            if(a > 0)
            {
                ans[i] = 'R';
                a --;
                wins ++;
            }
            else
                ans[i] = '0';
        }
    }

    for(int i = 0;i < n;i++)
    {
        if(ans[i] == '0')
        {
            if(a > 0)
            {
                ans[i] = 'R';
                a --;
            }
            else if(b > 0)
            {
                ans[i] = 'P';
                b --;
            }
            else
            {
                ans[i] = 'S';
                c --;
            }
        }
    }

    if(n % 2)
        n = (n / 2) + 1;
    else
        n = n / 2;

    if(wins >= n)
    {
        cout<<"YES\n";
        cout<<ans<<"\n";
    }
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        solve();
    }
    return 0;
}