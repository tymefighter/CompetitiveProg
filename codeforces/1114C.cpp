#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const int N = 1000005;
long long int INF = 1000000000000000000;
bitset<N> bs;
vector<int> primes;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = false;

    long long int i, j;

    for(i = 0;i < N;i++)
    {
        if(bs[i] == false)
            continue;

        for(j = i * i;j < N;j += i)
            bs[j] = false;
        
        primes.push_back(i);
    }
}

long long int n, b;

long long int getPowerFactorial(long long int p)     // Get power of prime 'p' in 'n' factorial
{
    long long int pw = p, ct = 0;

    while(pw <= n)
    {
        ct += n / pw;
        if(n / pw < p)
            break;
        pw *= p;
    }

    return ct;
}

void solve()
{
    int idx = 0;
    long long int pf, ct, ans = INF;

    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * pf > b)
            break;

        if(b % pf)
        {
            idx ++;
            continue;
        }
        ct = 0;
        while(b % pf == 0)
        {
            b /= pf;
            ct ++;
        }

        ans = min(ans, getPowerFactorial(pf) / ct);
        idx ++;
    }

    if(b != 1)
        ans = min(ans, getPowerFactorial(b));
    
    cout<<ans<<"\n";
}

int main()
{
    sieve();
    cin>>n>>b;
    solve();
    return 0;
}