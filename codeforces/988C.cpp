#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>

using namespace std;

int b[200005];
vector<pair<int, pair<int, int> > > a;
set<pair<int, int> > s;

void read()
{
    int k, n, i, j, sum;
    cin>>k;

    s.clear();
    for(i = 1;i <= k;i++)
    {
        cin>>n;
        sum = 0;
        for(j = 0;j < n;j++)
        {
            cin>>b[j];
            sum += b[j];
        }


        for(j = 0;j < n;j++)
        {
            if(s.find({sum - b[j], i}) == s.end())
            {
                a.push_back({sum - b[j], {i, j + 1}});
                s.insert({sum - b[j], i});
            }
        }

    }

    sort(a.begin(), a.end());
}

void solve()
{
    int i;
    for(i = 1;i < a.size();i++)
    {
        if(a[i].first == a[i - 1].first && a[i].second.first != a[i - 1].second.first)
            break;
    }

    if(i != a.size())
    {
        cout<<"YES\n";
        cout<<a[i - 1].second.first<<" "<<a[i - 1].second.second<<"\n";
        cout<<a[i].second.first<<" "<<a[i].second.second<<"\n";
    }
    else
        cout<<"NO\n";
}

int main()
{
    read();
    solve();
    return 0;
}