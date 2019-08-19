#include<iostream>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cmath>

using namespace std;

const long long int MAX_N = 46341;
bitset<MAX_N> is_prime;
vector<int> primes;
long long int l, u;

void sieve()
{
    primes.clear();
    is_prime.set();
    int i, j;

    is_prime[0] = is_prime[1] = false;
    for(i = 2;i <= MAX_N;i++)
    {
        if(!is_prime[i])
            continue;
        if(i * (i * 1ll) > MAX_N)
        {
            primes.push_back(i);
            continue;
        }

        for(j = i * i;j <= MAX_N;j += i)
            is_prime[j] = false;
        primes.push_back(i);
    }
}

bool is_prime_no(long long int n)
{
    long long int sqrn = sqrt(n);
    if(n <= MAX_N)
        return is_prime[n];
    for(long long int x : primes)
    {
        if(x > sqrn)
            return true;
        if(n % x == 0)
            return false;
    }

    return true;
}

void solve()
{
    long long int p1, p2, mi1, mi2, ma1, ma2;

    p1 = p2 = -1;
    for(long long int i = l;i <= u;i++)
    {
        if(is_prime_no(i))
        {
            if(p1 == -1)
            {
                mi1 = ma1 = p1 = i;
            }
            else if(p2 == -1)
            {
                mi2 = ma2 = p2 = i;
            }
            else
            {
                p1 = p2;
                p2 = i;
            }
            if(p2 - p1 < mi2 - mi1)
            {
                mi1 = p1;
                mi2 = p2;
            }
            if(p2 - p1 > ma2 - ma1)
            {
                ma1 = p1;
                ma2 = p2;
            }
        }
    }

    if(p1 == -1 || p2 == -1)
        printf("There are no adjacent primes.\n");
    else
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", mi1, mi2, ma1, ma2);

}

int main()
{
    sieve();
    while(cin>>l>>u)
        solve();
    return 0;
}