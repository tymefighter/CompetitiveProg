#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n;
pair<int, pair<int, int> > a[100005];

void read()
{
    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i].second.first>>a[i].second.second;
        a[i].first = a[i].second.second - a[i].second.first;
    }
}


long long int calc_dis()
{
    long long int val = 0;
    for(int i = 0;i < n;i++)
        val += (a[i].second.first*1ll) * (i) + (a[i].second.second*1ll) * (n - (i + 1));
    return val;
}

void solve()
{
    sort(a, a + n);
    cout<<calc_dis()<<"\n";
}

int main()
{
    read();
    solve();

    return 0;
}