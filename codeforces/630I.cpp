#include<iostream>

using namespace std;

long long int pw(const int &a, int k)
{
    if(k == 0)
        return 1;
    else if(k % 2)
        return pw(a, k - 1) * a;
    else
    {
        long long int val = pw(a, k / 2);
        return val * val;
    }
}

void solve()
{
    int n;
    cin>>n;

    long long int ans = (9 * pw(4, n - 3) * (n - 3)) + (6 * pw(4, n - 2));
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}