#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n;
pair<int, int> a[5005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i].first>>a[i].second;

    sort(a, a + n);
}

void solve()
{
    int val = a[0].second;

    for(int i = 1;i < n;i++)
    {
        if(a[i].second < val)
            val = a[i].first;
        else
            val = a[i].second;
    }

    cout<<val<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}