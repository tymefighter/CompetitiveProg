#include<iostream>

using namespace std;

const long long int MOD = 100000000000;
int n, m;

void solve()
{
    long long int ans = 1, val = n + 1 - m;

    while(val <= n)
    {
        ans *= val;
        while(ans % 10 == 0)
            ans /= 10;
        ans %= MOD;
        val++;
    }

    cout<<ans % 10<<"\n";
}

int main()
{
    while(cin>>n>>m)
        solve();
    return 0;
}