#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

const int MAX = 20000001;
bitset<MAX> bs;
vector<int> primes;
int ans[100005];
int s;

void reset()
{
    primes.clear();
    bs.set();
    bs[0] = bs[1] = false;
}

void sieve()
{
    int i, j;
    for(i = 2;i <= MAX;i++)
    {
        if(!bs[i])
            continue;
        if(i * (i * 1ll) > (MAX * 1ll))
        {
            primes.push_back(i);
            continue;
        }

        for(j = i * i;j <= MAX; j += i)
            bs[j] = false;
        
        primes.push_back(i);
    }
}

bool is_prime(int n)
{
    if(n <= MAX)
        return bs[n];

    int sqrn = sqrt(n);
    for(int x : primes)
    {
        if(x > sqrn)
            return true;
        else if(n % x == 0)
            return false;
    }

    return true;
}

void generate()
{
    int val = 0;
    ans[0] = 0;
    for(int i = 2;i <= 20000000;i++)
    {
        if(is_prime(i) && is_prime(i + 2))
        {
            val++;
            if(val > 100005)
                break;
            ans[val] = i;
        }
    }
}


int main()
{
    reset();
    sieve();
    generate();

    while(cin>>s)
        printf("(%d, %d)\n", ans[s], ans[s] + 2);
    return 0;
}