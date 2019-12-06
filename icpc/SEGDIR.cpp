#include<iostream>

using namespace std;

int n;
pair<pair<int, int>, int> a[10005];

void read()
{
    cin>>n;
    int l, r, v;

    for(int i = 0;i < n;i++)
    {
        cin>>l>>r>>v;
        a[i] = {{l, r}, v};
    }
}

void solve()
{
    int i, j, ct = 0;

    for(i = 0;i < n;i++)
    {
        ct = 0;
        for(j = 0;j < n;j++)
        {
            if(a[i].second != a[j].second)
                continue;
            
            if((a[i].first.second < a[j].first.first) || (a[j].first.second < a[i].first.first))
                continue;
            ct ++;
        }

        if(ct >= 3)
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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