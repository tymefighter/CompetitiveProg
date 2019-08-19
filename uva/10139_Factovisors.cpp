#include<iostream>
#include<cmath>
#include<bitset>
#include<vector>

using namespace std;

const int N = 46341;
int n, m;
bitset<N> bs;
vector<int> primes;

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

int get_power_in_fact(int p)
{
    int num = 0;
    for(long long int i = p;i <= n;i *= p)
        num += (n / i);
    return num;
}

bool solve()
{
    int pf = primes[0], idx = 0, pw, mt = m;
    while(pf * pf <= mt)
    {
        pw = 0;
        while(mt % pf == 0)
        {
            mt /= pf;
            pw++;
        }
        idx++;
        if(idx >= primes.size())
            break;
        if(!pw)
        {
            pf = primes[idx];
            continue;
        }
        if(get_power_in_fact(pf) < pw)
            return false;
        pf = primes[idx];
    }

    if(mt != 1)
        return get_power_in_fact(mt) >= 1;

    return true;
}

int main()
{
    sieve();
    while(cin>>n>>m)
    {
        if(solve())
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
    }
    return 0;
}