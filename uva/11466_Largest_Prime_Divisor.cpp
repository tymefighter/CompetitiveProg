#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>

using namespace std;

const int N = 10000000;
bitset<N> bs;
vector<int> primes;

long long int n;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = false;

    long long int i, j;
    for(i = 2;i <= N;i++)
    {
        if(!bs[i])
            continue;
        for(j = i * i;j <= N;j += i)
            bs[j] = false;
        primes.push_back(i);
    }
}

void solve()
{
    int idx = 0, ct = 0;
    long long int pf, ans = -1;

    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * pf > n)
            break;

        if(n % pf)
        {
            idx++;
            continue;
        }

        while(n % pf == 0)
            n /= pf;
        ct++;
        ans = pf;
        idx++;
    }

    if(n != 1)
    {
        ans = n;
        ct++;
    }

    if(ct == 1)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    sieve();
    while(cin>>n)
    {
        if(!n)
            break;
        n = abs(n);
        solve();
    }
}