#include<iostream>
#include<algorithm>

using namespace std;

int n;
string s;

void solve()
{
    string a;
    n = s.size();
    a.assign(n, '0');

    a[n - 1] = '1';
    int i = n - 1, ans = 0;

    while(a < s)
    {
        ans ++;

        if(i - 2 < 0)
            break;
        a[i] = '0';
        a[i - 2] = '1';
        i = i - 2; 
    }

    cout<<ans<<"\n";
}

int main()
{
    cin>>s;
    solve();
    return 0;
}