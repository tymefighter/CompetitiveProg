#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<cassert>

using namespace std;

long long int K = 32000, K2modp, z_0;
long long int Q, Q2modp;

vector<long long int> primes_z, v;
set<long long int> s;

void reset()
{
    primes_z.clear();
    v.clear();
    s.clear();
}

void get_prime_factors()
{
    long long int sqrn = sqrt(z_0);
    for(long long int n = 2;n <= sqrn;n++)
    {
        if(z_0 % n == 0)
        {
            primes_z.push_back(n);
            while(z_0 % n == 0)
                z_0 /= n;
        }
    }

    if(z_0 > 2)
        primes_z.push_back(z_0);

    sort(primes_z.begin(), primes_z.end());

}

void form_eq()
{
    long long int i, val;
    for(int idx = 0;idx < primes_z.size();idx++)
    {
        i = 0;
        val = 0;
        while(s.find(val) != s.end())
        {
            i++;
            val = (i * i) % primes_z[idx];
        }

        s.insert(val);
        v.push_back(i);
    }
}

void extended_gcd(long long int a, long long int b, long long int &X, long long int &Y)
{
    long long int x1, x2, x, y1, y2, y, r1, r2, r, q;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    r2 = a, r1 = b;

    while(r1)
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - q * x1;
        y = y2 - q * y1;
        x2 = x1, y2 = y1, r2 = r1;
        x1 = x, y1 = y, r1 = r;
    }

    X = x2, Y = y2;
}

long long int chinese_remainder_theorem()
{
    long long int a1, m1, a2, m2, p, q, x;
    a1 = v[0], m1 = primes_z[0];

    for(int i = 1;i < v.size();i++)
    {
        a2 = v[i];
        m2 = primes_z[i];

        extended_gcd(m1, m2, p, q);

        x = (a1 * m2 * q + a2 * m1 * p) % (m1 * m2);
        m1 = m1 * m2;
        if(x < 0)
            x += m1;
        a1 = x;
    }

    return x;
}

void get_ans()
{
    int i;
    for(i = 0;i < v.size();i++)
    {
        if(Q2modp == (v[i] * v[i]) % primes_z[i])
            break;
    }

    cout<<"2 "<<primes_z[i]<<endl;
}

bool solve()
{
    cout<<"1 "<<K<<endl;
    cin>>K2modp;
    assert(K2modp != -1ll);
    if(K2modp == -1ll)
        return false;

    z_0 = (K * K) - K2modp;
    get_prime_factors();
    form_eq();

    Q = chinese_remainder_theorem();
    
    cout<<"1 "<<Q<<endl;
    cin>>Q2modp;
    assert(Q2modp != -1ll);
    if(Q2modp == -1ll)
        return false;

    get_ans();

    string str;

    cin>>str;
    assert(str == "Yes");
    if(str == "No")
        return false;
    
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        reset();
        if(!solve())
            break;
    }

    assert(t == -1);

    return 0;
}