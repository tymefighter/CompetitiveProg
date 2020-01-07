#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<string> a;
int n, d;

void read()
{
    a.clear();
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin>>a[i];
}

void solve()
{
    map<string, int> m;
    int ans;

    for(int i = 0;i < min(d, n);i++)
        m[a[i]] ++;
    ans = m.size();

    int val = ans;
    for(int i = d;i < n;i++)
    {
        m[a[i - d]] --;
        if(m[a[i - d]] == 0)
            val --;
        
        m[a[i]] ++;
        if(m[a[i]] == 1)
            val ++;
        
        ans = max(ans, val);
    }
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        read();
        solve();
    }

    return 0;
}