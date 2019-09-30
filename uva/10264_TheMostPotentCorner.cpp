#include<iostream>
#include<map>

using namespace std;

int n;
map<long long int, int> m, pt;

void read()
{
    int x;
    m.clear();
    pt.clear();
    
    for(int i = 0;i < (1 << n);i++)
    {
        cin>>x;
        m[i] = x;
    }
}

void solve()
{
    int i, j, k;

    for(i = 0;i < (1 << n);i++)
    {
        pt[i] = 0;
        for(j = 1;j < (1 << n);j = (j << 1))
        {
            k = i ^ j;
            pt[i] += m[k];
        }
    }

    int ans = 0;
    for(i = 0;i < (1 << n);i++)
    {
        for(j = 1;j < (1 << n);j = (j << 1))
            ans = max(ans, pt[i] + pt[i ^ j]);
    }

    cout<<ans<<"\n";
}

int main()
{
    while(cin>>n)
    {
        read();
        solve();
    }
    return 0;
}