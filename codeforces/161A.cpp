#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int n, m;
int a[100005], b[100005];
int x, y;
vector<pair<int, int> > ans;

void read()
{
    cin>>n>>m>>x>>y;

    int i;
    for(i = 0;i < n;i++)
        cin>>a[i];
    for(i = 0;i < m;i++)
        cin>>b[i];
    
    sort(a, a + n);
    sort(b, b + m);
}

void solve()
{
    int i = 0, j = 0;

    while(i < n && j < m)
    {
        if(b[j] < a[i] - x)
            j++;
        else if(b[j] > a[i] + y)
            i++;
        else
        {
            ans.push_back({i+1, j+1});
            i ++, j++;
        }
    }

    cout<<ans.size()<<"\n";
    for(pair<int, int> x : ans)
        cout<<x.first<<" "<<x.second<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}