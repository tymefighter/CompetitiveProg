#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int b[200005];
vector<int> a;

void read()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>b[i];
    sort(b, b + n);

    int ct = 1;
    a.clear();
    for(int i = 1;i < n;i++)
    {
        if(b[i] == b[i-1])
            ct++;
        else
        {
            a.push_back(ct);
            ct = 1;
        }
    }
    a.push_back(ct);


    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
}

void solve()
{
    int prev = a[0], ans = a[0];

    for(int i = 1;i < a.size();i++)
    {
        prev = max(min(a[i], prev - 1), 0);
        ans += prev;
    }

    cout<<ans<<"\n";
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        read();
        solve();
    }
    return 0;
}