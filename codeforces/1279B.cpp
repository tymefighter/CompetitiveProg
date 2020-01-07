#include<iostream>

using namespace std;

const int N = 100005;
int n;
long long a[N], pre[N], s;

void read()
{
    cin>>n>>s;
    cin>>a[0];
    pre[0] = a[0]; 
    for(int i = 1;i < n;i++)
    {
        cin>>a[i];
        pre[i] = pre[i - 1] + a[i];
    }
}

int b_search(long long x)
{
    int low = 0, high = n - 1, mid;

    if(pre[high] <= x)
        return high;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid < n - 1 && pre[mid] <= x && pre[mid + 1] > x)
            return mid;
        else if(mid < n - 1 && pre[mid + 1] <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void solve()
{
    int idx = b_search(s);
    if(idx == n - 1)
    {
        cout<<"0\n";
        return;
    }

    idx ++;

    int ans = -1, ans_val = -1, val;
    for(int i = 0;i <= idx;i++)
    {
        val = b_search(s + a[i]);
        if(val > ans_val)
        {
            ans = i;
            ans_val = val;
        }
    }

    cout<<ans + 1<<"\n";
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