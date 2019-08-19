#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>

using namespace std;

const int N = 46341;
bitset<N> bs;
vector<int> primes;
int n;

void sieve()
{
    primes.clear();
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
    int idx = 0, pf = primes[0], ct = 0;

    if(n < 0)
    {
        cout<<"-1";
        ct++;
        n = -n;
    }

    while(idx < primes.size() && pf * (pf * 1ll) <= n * 1ll)
    {
        if(n % pf)
        {
            idx++;
            if(idx >= primes.size())
                break;
            pf = primes[idx];
            continue;
        }

        while(n % pf == 0)
        {
            n /= pf;
            if(ct)
                cout<<" x ";
            cout<<pf;
            ct++;
        }

        idx++;
        if(idx >= primes.size())
            break;
        pf = primes[idx];
    }

    if(n != 1)
    {
        if(ct)
            cout<<" x ";
        cout<<n;
        ct++;
    }

    cout<<"\n";
}

int main()
{
    sieve();
    while(cin>>n)
    {
        if(!n)
            break;
        cout<<n<<" = ";
        solve();
    }
    return 0;
}