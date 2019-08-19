#include<iostream>
#include<utility>
#include<unordered_map>

using namespace std;

int n;
int p[100005];
unordered_map<int, pair<long long int, long long int> > m;

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>p[i];
        p[i] ^= (i > 0 ? p[i - 1] : 0);
    }
}

void solve()
{
    m.clear();
    long long int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(m.find(p[i]) == m.end())
        {
            m[p[i]] = {1, -(i + 1)};
            if(p[i] == 0)
                ans += i;
        }
        else
        {
            ans += m[p[i]].first * i + m[p[i]].second;
            m[p[i]].first ++;
            m[p[i]].second -= (i + 1);
            if(p[i] == 0)
                ans += i;
        }
    }

    cout<<ans<<"\n";
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