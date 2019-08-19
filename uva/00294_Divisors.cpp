#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<cstdio>

using namespace std;

const int N = 31623;
bitset<N> bs;
vector<int> primes;

int L, U;

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

long long int num_div(int n)
{
    int idx = 0, pf, ct, ans = 1;

    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * (pf * 1ll) > n)
            break;
        if(n % pf)
        {
            idx++;
            continue;
        }
        ct = 0;
        while(n % pf == 0)
        {
            n /= pf;
            ct++;
        }

        ans *= (1 + ct);
        idx++;
    }

    if(n != 1)
        ans *= 2;
    return ans;
}

void solve()
{
    long long int ans = -1, val;
    int no = -1;

    for(int i = L;i <= U;i++)
    {
        val = num_div(i);
        if(val > ans)
        {
            ans = val;
            no = i;
        }
    }

    printf("Between %d and %d, %d has a maximum of %lld divisors.\n", L, U, no, ans);
}

int main()
{
    int t;
    sieve();
    cin>>t;
    while(t--)
    {
        cin>>L>>U;
        solve();
    }
    return 0;
}