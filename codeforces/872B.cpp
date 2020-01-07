#include<iostream>

using namespace std;

const int INF = 1000000000;
int n, k, a[100005];

void read_solve()
{
    cin>>n>>k;

    int min_val = INF, max_val = -INF;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        min_val = min(min_val, a[i]);
        max_val = max(max_val, a[i]);
    }

    if(k == 1)
        cout<<min_val<<"\n";
    else if(k == 2)
        cout<<max(a[0], a[n - 1])<<"\n";
    else
        cout<<max_val<<"\n";
}

int main()
{
    read_solve();
    return 0;
}