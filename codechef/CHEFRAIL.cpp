#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const long N = 100001;
vector<int> primes;
bitset<N> b;

void sieve()
{
    b.set();
    for(int i = 2;i < N;i++)
    {
        if(!b[i])
            continue;
        
        primes.push_back(i);
        for(long j = i * ((long) i);j < (long)N;j += i)
            b[j] = false;
    }
}

vector<pair<long, long> > prime_fac; // (prime, power of prime)

void get_pf(long val)
{
    prime_fac.clear();

    for(int i = 0;i < primes.size();i++)
    {
        if(primes[i] * ((long) primes[i]) > val)
            break;
        
        if(val % primes[i] != 0)
            continue;
        
        int ct = 0;
        while(val % primes[i] == 0)
        {
            val /= primes[i];
            ct ++;
        }
        prime_fac.push_back({primes[i], ct});
    }

    if(val != 1)
        prime_fac.push_back({val, 1});
}

int num;
vector<long> fac[N];

void place_fac(int idx, long val)
{
    if(val >= N) // faster !!!!
        return;

    if(idx == prime_fac.size())
    {
        fac[num].push_back(val);
        return;
    }
    
    long pw_val = 1;
    for(int i = 0;i <= prime_fac[idx].second;i++)
    {
        place_fac(idx + 1, val * pw_val);
        pw_val *= prime_fac[idx].first;
    }
}

void get_fac(long val)
{
    fac[num].clear();
    get_pf(val);
    place_fac(0, 1);
}

void compute_fac()
{
    for(num = 0;num < N;num++)
        get_fac(num * ((long) num));
}

int n, m;
int x[N], y[N];
bool y_pos[N], y_neg[N], x_pos[N], x_neg[N]; // maps
bool has_origin;

void set_map()
{
    for(long i = 0;i < N;i++)
    {
        y_pos[i] = false;
        y_neg[i] = false;
        x_pos[i] = false;
        x_neg[i] = false;
    }
    
    for(int i = 0;i < n;i++)
    {
        if(x[i] > 0)
            x_pos[x[i]] = true;
        else
            x_neg[abs(x[i])] = true;
    }

    for(int i = 0;i < m;i++)
    {
        if(y[i] > 0)
            y_pos[y[i]] = true;
        else
            y_neg[abs(y[i])] = true;
    }
}

void read()
{
    has_origin = false;
    scanf("%d %d", &n, &m);

    for(int i = 0;i < n;i++)
    {
        scanf("%d", &x[i]);
        if(x[i] == 0)
        {
            has_origin = true;
            i --;
            n --;
        }
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%d", &y[i]);
        if(y[i] == 0)
        {
            has_origin = true;
            i --;
            m --;
        }
    }

    set_map();
}

void solve()
{
    long ans = 0, val;

    for(int i = 0;i < n;i++)
    {
        val = x[i] * ((long) x[i]);
        for(auto f : fac[abs(x[i])])
        {
            if(f >= N || (val / f) >= N)
                continue;
            if(y_neg[f] && y_pos[val / f])
                ans ++;
        }
    }

    for(int i = 0;i < m;i++)
    {
        val = y[i] * ((long) y[i]);
        for(auto f : fac[abs(y[i])])
        {
            if(f >= N || (val / f) >= N)
                continue;
            if(x_neg[f] && x_pos[val / f])
                ans ++;
        }
    }

    if(has_origin)
        ans += n * ((long) m);

    printf("%ld\n", ans);
}

int main()
{
    int t;
    sieve();
    compute_fac();

    scanf("%d", &t);
    while(t--)
    {
        read();
        solve();
    }
    return 0;
}