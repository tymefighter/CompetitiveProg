#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
vector<pair<float, pair<int, int> > > f;

int gcd(int a, int b)
{
    if(b > a)
        swap(a, b);

    if(b == 0)
        return a;

    return gcd(b, a % b);
}

void solve()
{
    f.clear();
    int i, j;
    for(i = 1;i <= n;i++)
    {
        for(j = 1;j < i;j++)
        {
            if(gcd(i, j) == 1)
                f.push_back({j / (float)i, {j, i}});
        }
    }

    f.push_back({1.0, {1, 1}});
    sort(f.begin(), f.end());
    cout<<f[k - 1].second.first<<"/"<<f[k - 1].second.second<<"\n";
}

int main()
{
    while(cin>>n>>k)
        solve();

    return 0;
}