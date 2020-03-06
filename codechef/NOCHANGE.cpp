#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1005;
int n, p;
pair<int, int> d[N];

void read()
{
    cin>>n>>p;
    for(int i = 0;i < n;i++)
    {
        cin>>d[i].first;
        d[i].second = i;
    }
}

void solve()
{
    for(int i = 0;i < n;i++)
    {
        if(p % d[i].first)
        {
            cout<<"YES ";
            for(int j = 0;j < n;j++)
            {
                if(i == j)
                    cout<<(p / d[i].first) + 1<<" ";
                else
                    cout<<"0 ";
            }
            cout<<"\n";
            return;
        }
    }

    sort(d, d + n);
    for(int i = 1;i < n;i++)
    {
        if(d[i].first % d[i - 1].first)
        {
            cout<<"YES ";
            for(int j = 0;j < n;j++)
            {
                if(j == d[i - 1].second)
                    cout<<((p - d[i].first) / d[i - 1].first) + 1<<" ";
                else if(j == d[i].second)
                    cout<<"1 ";
                else
                    cout<<"0 ";
            }
            cout<<"\n";
            return;
        }
    }

    cout<<"NO\n";    
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