#include<iostream>

using namespace std;

int n;
int loc[200005];

void read()
{
    cin>>n;
    int x;
    for(int i = 1;i <= n;i++)
    {
        cin>>x;
        loc[x] = i;
    }
}

void solve()
{
    int minIdx = n + 1, maxIdx = -1;
    string ans;
    for(int i = 1;i <= n;i++)
    {
        minIdx = min(minIdx, loc[i]);
        maxIdx = max(maxIdx, loc[i]);

        if(maxIdx - minIdx + 1 == i)
            ans.push_back('1');
        else
            ans.push_back('0');
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