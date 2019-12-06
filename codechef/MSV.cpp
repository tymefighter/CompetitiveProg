#include<iostream>
#include<vector>
#include<set>

using namespace std;

int n, max_val, a[100005];
vector<vector<int> > m;

void read()
{
    cin>>n;

    max_val = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        max_val = max(a[i], max_val);
    }

    m.clear();
    m.resize(max_val + 5);

    for(int i = 0;i < n;i++)
        m[a[i]].push_back(i);
}

int b_search(int curr_x, int x, int val)
{
    if(m[x].size() == 0)
        return 0;
    
    int low = 0, high = m[x].size() - 1, mid, sz = m[x].size();

    if(m[x][high] < val)
        return high + 1;

    if(m[x][low] >= val)
        return 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid < sz - 1 && m[x][mid] < val && m[x][mid + 1] >= val)
            return mid + 1;
        else if(mid < sz - 1 && m[x][mid + 1] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

void solve()
{
    set<int> s;
    int val, curr, ans = 0;

    for(int i = n - 1;i >= 0;i --)
    {
        if(s.find(a[i]) != s.end())
            continue;
        
        s.insert(a[i]);

        val = a[i];
        curr = 0;
        for(int x = val;x <= max_val; x += val)
            curr += b_search(val, x, i);
        
        ans = max(ans, curr);
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