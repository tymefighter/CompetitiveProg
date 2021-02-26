#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long powmod (long long a, long long b, long long p) {
    long long res = 1;
    while (b)
        if (b & 1)
            res = (long long) (res * 1ll * a % p),  --b;
        else
            a = (long long) (a * 1ll * a % p),  b >>= 1;
    return res;
}

long long generator (long long p) {
    vector<long long> fact;
    long long phi = p-1,  n = phi;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (long long res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

inline long long inverse_fermat(long long a, long long p) {
    return powmod(a, p - 2, p);
}

int main() {

    cout << generator(998244353) << "\n";
    long long val = powmod(generator(998244353), 952, 998244353);
    cout << val << "\n";

    cout << inverse_fermat(val, 998244353) << "\n";

    return 0;
}
