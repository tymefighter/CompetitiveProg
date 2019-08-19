#include<iostream>
#include<vector>
#include<cstdio>
#include<bitset>
#include<cmath>

using namespace std;

const int N = 32;
bitset<N> bs;
vector<int> primes;

int s;

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

int sum_div(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    
    int idx = 0, pf, ans = 1, ct;

    while(idx < primes.size())
    {
        pf = primes[idx];
        if(pf * pf > n)
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

        ans *= ((int)pow(pf, ct + 1) - 1) / (pf - 1);
    }

    if(n != 1)
        ans *= ((int)pow(n, 2) - 1) / (n - 1);

    return ans;
}

void solve(int c_no)
{
    int n = s;
    while(n >= 0)
    {
        if(sum_div(n) == s)
            break;
        n--;
    }

    printf("Case %d: %d\n", c_no, n);
}

int main()
{
    int c = 1;

    sieve();
    while(cin>>s)
    {
        if(!s)
            break;
        solve(c);
        c++;
    }
    return 0;
}