#include<iostream>
#include<cstring>
#include<cmath>
#include<set>

using namespace std;

set<int> s;
bool is_prime[1000005];

void generate_primes(int n)
{
    memset(is_prime, false, sizeof(is_prime));
    int i, j;
    for(i = 2;i <= n;i++)
    {
        if(is_prime[i])
            continue;
        for(j = 2;i * j <= n;j++)
            is_prime[i*j] = true;
        s.insert(i);
    }
}

bool check(long long int x)
{
    if(x == 1)
        return false;
    int a = sqrt(x);


    if(a * (a*1ll) != x)
        return false;

    
    return (s.find(a) != s.end());
}

int main()
{
    int n;
    long long int x;

    generate_primes(1000005);
    cin>>n;

    for(int i = 0;i < n;i++)
    {
        cin>>x;
        if(check(x))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}