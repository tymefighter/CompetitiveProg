#include<iostream>

using namespace std;

int n, m;
long long int x, pre1[100005], pre2[100005];

void read()
{
    cin>>n>>m>>x;

    for(int i = 0;i < n;i++)
    {
        cin>>pre1[i];
        if(i)
            pre1[i] += pre1[i - 1];
    }
    for(int i = 0;i < m;i++)
    {
        cin>>pre2[i];
        if(i)
            pre2[i] += pre2[i - 1];
    }
}

int b_search(long long int val)
{
    if(pre2[m - 1] <= val)
        return m - 1;

    int low = 0, high = m - 1, mid;
    mid = (low + high) / 2;

    while(low <= high)
    {
        if(mid < m - 1 && pre2[mid] <= val && pre2[mid + 1] > val)
            return mid;
        else if(mid < m - 1 && pre2[mid + 1] <= val)
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    return -1;
}

void solve()
{
    int i = 0, j, ans;

    j = b_search(x);
    ans = j + 1;

    for(i = 0;i < n;i++)
    {
        if(x < pre1[i])
            break;
        j = b_search(x - pre1[i]);
        ans = max(ans, (i + 1) + (j + 1));
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