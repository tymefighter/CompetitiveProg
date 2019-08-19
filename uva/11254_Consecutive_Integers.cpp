#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

long long int n;

void solve()
{
    long long int x, r;
    long long int val = (-1 + sqrt(1 + 8 * n)) / 2, val1, val2;

    for(r = val;r >= 0;r--)
    {
        val1 = n - (r * (r + 1)) / 2;
        val2 = r + 1;

        if(val1 % val2)
            continue;
        
        x = val1 / val2;
        break;
    }

    printf("%lld = %lld + ... + %lld\n", n, max(x, 1ll), x + r);
}

int main()
{
    while(cin>>n)
    {
        if(n < 0)
            break;
        solve();
    }

    return 0;
}