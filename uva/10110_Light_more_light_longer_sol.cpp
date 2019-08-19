#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>

using namespace std;

const int N = 65536;
bitset<N> bs;
vector<int> primes;
long int n;

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
    long long int num_div = 1;
    int idx = 0, pf, ct;

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

        num_div *= (1 + ct);
        idx++;
    }

    if(n != 1)
        num_div *= 2;
    if(num_div % 2)
        cout<<"yes\n";
    else
        cout<<"no\n";
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