#include<iostream>
#define VAL 1000000007

using namespace std;

long long int n, k;

long long int solve()
{
    long long int r, ans;

    if(n >= k)
        return (k - 1ll) % VAL;

    r = ((k - 2) / (n - 1)) % VAL;
    long long int t1, t2, t3, t4;

    t1 = (k - 1) % VAL;
    t2 = (r * (k % VAL)) % VAL;
    t3 = ((n % VAL) * (((r * (r + 1)) / 2) % VAL)) % VAL;
    t4 = ((r * (r - 1)) / 2) % VAL;

    ans = (t1 + t2 - t3 + t4) % VAL;

    if(ans < 0)
        ans = VAL + ans;

    return ans;
}

int main()
{
    long long int ans;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        ans = solve();
        cout<<ans<<"\n";
    }

    return 0;
}