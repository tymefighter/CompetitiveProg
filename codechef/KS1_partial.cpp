#include<iostream>
#include<map>
#include<utility>

using namespace std;

map<int, int> m1, m2;
int n;
int a[1005];

void read()
{
    cin>>n;
    cin>>a[0];
    for(int i = 1;i < n;i++)
    {
        cin>>a[i];
        a[i] ^= a[i - 1];
    }
}

void solve()
{
    int i, j, k, ans = 0;
    for(j = 1;j < n;j++)
    {
        m1.clear();
        m2.clear();
        for(i = 0;i < j;i++)
            m1[a[j - 1] ^ (i > 0 ? a[i - 1] : 0)]++;

        for(k = j;k < n;k++)
            m2[a[k] ^ a[j - 1]]++;

        for(pair<int, int> pr : m1)
            ans += pr.second * m2[pr.first];
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