#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n, m;
int a[100005];
pair<int, long long int> b[100005];

void read()
{
    cin>>n>>m;

    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i < m;i++)
        cin>>b[i].first>>b[i].second;

    sort(b, b + m);

    for(int i = 1;i < m;i++)
        b[i].second += b[i - 1].second;
}

long long int b_search(int val)
{
    if(val >= b[m - 1].first)
        return b[m - 1].second;

    if(val < b[0].first)
        return -10;

    int low = 0, high = m - 1, mid;
    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid <= m - 2 && b[mid].first <= val && val < b[mid + 1].first)
            return b[mid].second;
        else if(mid <= m - 2 && b[mid + 1].first <= val)
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    return -1;
}

void solve()
{
    long long int ans;
    for(int i = 0;i < n;i++)
    {
        ans = b_search(a[i]);

        if(ans < 0)
            cout<<"0 ";
        else
            cout<<ans<<" ";
    }
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}