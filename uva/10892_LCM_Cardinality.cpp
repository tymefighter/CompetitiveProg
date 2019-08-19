#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>

using namespace std;

const int N = 44722;
bitset<N> bs;
vector<int> primes;
int n;

void sieve()
{
    primes.clear();
    bs.set();
    bs[0] = bs[1] = false;

    for(long long int i = 2;i <= N;i++)
    {
        if(!bs[i])
            continue;
        for(long long int j = i * i;j <= N;j += i)
            bs[j] = false;
        primes.push_back(i);
    }
}

void solve()
{
    int idx = 0, pf = primes[0], pw, ans = 1, n_copy = n;
    while(idx < primes.size() && pf * (pf * 1ll) <= (n * 1ll))
    {
        if(n % pf)
        {
            idx++;
            pf = primes[idx];
            continue;
        }
        pw = 0;
        while(n % pf == 0)
        {
            n /= pf;
            pw ++;
        }
        ans *= (2 * pw + 1);
        idx++;
        pf = primes[idx];
    }

    if(n != 1)
        ans *= 3;
    ans = (ans + 1) / 2;
    cout<<n_copy<<" "<<ans<<"\n";
}

int main()
{
    sieve();
    while(cin>>n)
    {
        if(!n)
            break;
        solve();
    }
    return 0;
}