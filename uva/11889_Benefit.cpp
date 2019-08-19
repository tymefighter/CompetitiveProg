#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>

using namespace std;

const int N = 3163;
bitset<N> bs;
vector<int> primes;

int a, c, last_a, last_c;
vector<int> p_a, p_c;


void sieve()
{
    bs.set();
    bs[0] = bs[1] = false;

    int i, j;
    for(i = 2;i <= N;i++)
    {
        if(!bs[i])
            continue;
        for(j = i * i;j <= N;j += i)
            bs[j] = false;
        primes.push_back(i);
    }
}

void get_prime_fac(int n, vector<int> &p, int &last)
{
    int idx = 0, pf, ct;
    p.assign(primes.size(), 0);
    last = -1;


    while(idx < primes.size())
    {
        pf = primes[idx];
        
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

        p[idx] = ct;
        idx++;
    }

    if(n != 1)
        last = n;
}

void solve()
{
    int ans = 1;
    get_prime_fac(a, p_a, last_a);
    get_prime_fac(c, p_c, last_c);

    if(last_a != -1 && last_a != last_c)
    {
        cout<<"NO SOLUTION\n";
        return;
    }

    if(last_a == -1 && last_c != -1)
        ans = last_c;

    for(int i = 0;i < primes.size();i++)
    {
        if(p_a[i] > p_c[i])
        {
            cout<<"NO SOLUTION\n";
            return;
        }
        else if(p_a[i] < p_c[i])
            ans *= (int)pow(primes[i], p_c[i]);
    }

    cout<<ans<<"\n";
}

int main()
{
    int t;
    sieve();

    cin>>t;
    while(t--)
    {
        cin>>a>>c;
        solve();
    }
    return 0;
}