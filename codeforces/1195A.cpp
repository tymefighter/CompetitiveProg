#include<iostream>

using namespace std;

int n, k;
int c[1005];

void read()
{
    cin>>n>>k;
    for(int i = 0;i <= k;i++)
        c[i] = 0;

    int x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        c[x]++;
    }
}

void solve()
{
    int sum_val = 0, val = 0;
    for(int i = 0;i <= k;i++)
        sum_val += 2 * (c[i] / 2);

    val = n - sum_val;
    if(val % 2)
        val = val / 2 + 1;
    else
        val = val / 2;

    cout<<sum_val + val<<"\n";
}

int main()
{
    read();
    solve();
    return 0;
}