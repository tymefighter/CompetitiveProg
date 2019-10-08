#include<iostream>

using namespace std;

int y, n, a[100005];

void read()
{
    for(int i = 0;i < n;i++)
        cin>>a[i];
}

int b_search(int val)
{
    int low = 0, high = n - 1, mid;

    if(a[high] <= val)
        return high;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid < n - 1 && a[mid] <= val && a[mid + 1] > val)
            return mid;
        else if(mid < n - 1 && a[mid + 1] <= val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void solve()
{
    int j, start = -1, end = -1, ans = 0, val;
    for(int i = 0;i < n;i++)
    {
        j = b_search(a[i] + y - 1);
        val = j - i + 1;

        if(val > ans)
        {
            ans = val;
            start = a[i];
            end = a[j];
        }
    }

    cout<<ans<<" "<<start<<" "<<end<<"\n";
}

int main()
{
    while(cin>>y>>n)
    {
        read();
        solve();
    }
    return 0;
}