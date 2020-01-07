#include<iostream>
#include<algorithm>

using namespace std;

int n, a[100005];

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];

    sort(a, a + n);
}

int b_search(double x, int high)
{
    int low = 0, mid;

    if(a[0] >= x)
        return 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid > 0 && a[mid] >= x && a[mid - 1] < x)
            return mid;
        else if(mid > 0 && a[mid - 1] >= x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

void solve()
{
    long long ans = 0;
    int idx;
    for(int i = 1;i < n;i++)
    {
        idx = b_search((double)a[i] / 2.0, i - 1);
        if(idx == -1)
            continue;
        ans += (i - idx);
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