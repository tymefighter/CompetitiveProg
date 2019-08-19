#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const int mod1 = 1000000, mod2 = 1000000007;
const int N = 1005;
vector<int> primes;
bitset<N> bs;

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

long long int get_pf(int x)
{   
    int idx = 0;
    long long int pf, sum = 0;

    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * pf > x)
            break;
        
        if(x % pf)
        {
            idx++;
            continue;
        }

        sum = (sum + pf) % mod1;
        while(x % pf == 0)
        {
            x /= pf;
        }
        idx++;
    }

    return sum;
}

long long int ct[100005][105];

long long int part(int n, int k)
{
    int i, j;
    for(i = 0;i <= k;i++)
        ct[0][i] = 0;
    for(i = 0;i <= n;i++)
        ct[i][0] = 0;

    for(i = 1;i <= n;i++)
    {
        ct[i][1] = 1;

        if(i < k)
            ct[i][i] = 1;
    }

    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= k;j++)
            ct[i][j] = ((j * ct[i - 1][j]) % mod2 + ct[i - 1][j - 1]) % mod2;
    }

    return ct[n][k];
}

int getSubsets(int k, int n, vector<int> arr)
{
    cin>>k>>n;
    long long int m = 0;
    for(int x : arr)
    {
        cin>>x;
        m = (m + get_pf(x)) % mod1;
    }

    return part(m, k);
}

int get()
{
    sieve();
    read_solve();

    return 0;
}