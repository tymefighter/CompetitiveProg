#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;
int a[200005], pos_sort[200005];
pair<int, int> b[200005];
long long int ans;

void read()
{
    cin>>n>>m>>k;

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        b[i] = {a[i], i};
    }

    sort(b, b + n);
    reverse(b, b + n);

    ans = 0;

    for(int i = 0;i < n;i++)
    {
        pos_sort[b[i].second] = i;
        if(i < m * k)
            ans += b[i].first;
    }
}

void solve()
{
    int ct = 0, seen = 0;
    cout<<ans<<"\n";

    for(int i = 0;i < n;i++)
    {
        if(pos_sort[i] < m * k)
            ct ++;
        
        if(ct == m)
        {
            seen += m;
            if(seen == m * k)
                break;
            ct = 0;
            cout<<i + 1<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}