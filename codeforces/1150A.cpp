#include<iostream>

using namespace std;

int init, min_buy, max_sell;

void read()
{
    int n, m, x;

    min_buy = 2000;
    max_sell = -1;

    cin>>n>>m>>init;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        min_buy = min(min_buy, x);
    }

    for(int i = 0;i < m;i++)
    {
        cin>>x;
        max_sell = max(max_sell, x);
    }

}

void solve()
{
    int ans;
    if(max_sell > min_buy)
        ans = max_sell * (init / min_buy) + (init % min_buy);
    else
        ans = init;

    cout<<ans<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}