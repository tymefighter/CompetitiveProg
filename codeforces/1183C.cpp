#include<iostream>

using namespace std;

long long int k, n, a, b;

void solve()
{
    if(k <= n * b)
    {
        cout<<"-1\n";
        return;
    }

    long long int val1, val2, ans;
    val1 = (k - n * b);
    val2 = (a - b);

    // eq: (k - n * b) / (a - b)
    if(val1 % val2 == 0)
        ans = (val1 / val2) - 1;
    else
        ans = (val1 / val2); 

    ans = min(ans, n);
    cout<<ans<<"\n";
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        cin>>k>>n>>a>>b;
        solve();
    }
    return 0;
}