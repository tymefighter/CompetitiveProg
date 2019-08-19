#include<iostream>

using namespace std;

int n, w;
int c[1005];

void read()
{
    cin>>n>>w;

    for(int i = 0;i < n;i++)
    {
        cin>>c[i];
        if(i > 0)
            c[i] += c[i - 1];
    }
}

void solve()
{
    int min_val = 0, max_val = w;

    for(int i = 0;i < n;i++)
    {
        min_val = max(min_val, -c[i]);
        max_val = min(max_val, w - c[i]);
    }

    cout<<max(max_val - min_val + 1, 0)<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}