#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k, ans;
vector<int> a;

void reset()
{
    ans = 0;
    a.clear();
}

void read()
{
    cin>>n>>k;
    int x;
    while(n --)
    {
        cin>>x;
        if(x <= k)
            ans += x;
        else
            a.push_back(x - k);
    }
    n = a.size();
    ans += n * k;
    sort(a.begin(), a.end());
}

void solve()
{
    if(n == 0)
    {
        cout<<ans<<"\n";
        return;
    }
    else if(n == 1)
    {
        ans += a[0];
        cout<<ans<<"\n";
        return;
    }
    int sumPrev = 0, last = a[n - 2]; // sumPrev: sum of a0..an-3, last: an-2

    for(int i = 0;i < n - 2;i++)
        sumPrev += a[i];
    
    if(sumPrev < last)
        ans += a[n - 1] - (last - sumPrev);
    else if(sumPrev > last)
    {
        if((sumPrev % 2) == (last % 2))
            ans += a[n - 1];
        else
            ans += a[n - 1] - 1;
    }
    else
    {
        ans += a[n - 1];
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        reset();
        read();
        solve();
    }
    return 0;
}

