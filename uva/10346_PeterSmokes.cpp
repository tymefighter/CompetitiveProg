#include<iostream>

using namespace std;

int n, k;

void solve()
{
    int sum = 0, val;

    while(n)
    {
        if(n >= k)
            val = n % k;
        else
            val = 0;

        sum += n - val;
        n /= k;
        n += val;
    }

    cout<<sum<<"\n";
}

int main()
{
    while(cin>>n>>k)
        solve();

    return 0;
}