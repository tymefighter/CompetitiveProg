#include<iostream>
#include<vector>
#include<cstdio>
#include<bitset>

using namespace std;

const int N = 31623;
bitset<N> bs;
vector<int> primes;

int n;

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

int EulerPhi()
{
    int idx = 0, pf, ans = n;
    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * (pf * 1ll) > n)
            break;
        if(n % pf == 0)
            ans -= ans / pf;
        while(n % pf == 0)
            n /= pf;
        idx++;
    }
    if(n != 1)
        ans -= ans / n;

    return ans;
}

void solve()
{
    if(n == 1)
    {
        cout<<"1\n"; // include only 0
        return;
    }

    cout<<EulerPhi()<<"\n"; // remove 1 and include 0
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