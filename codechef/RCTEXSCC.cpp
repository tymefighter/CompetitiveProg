#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long binaryExp(long long a, long long n) {
    if(n == 0) return 1;
    else if(n % 2 == 1) return (a * binaryExp(a, n - 1)) % MOD;
    else {
        long long val = binaryExp(a, n / 2);
        return (val * val) % MOD;
    }
}

inline long long inverse(long long a) {
    return binaryExp(a, MOD - 2);
}

int main() {

    long long m, n, k, expecNumScc;

    scanf("%lld %lld %lld ", &m, &n, &k);
    expecNumScc = m * n - 1;

    if(m == 1)
        expecNumScc = (expecNumScc + 1 - ((n - 1) * inverse(k)) % MOD) % MOD;
    else
        expecNumScc = (
            expecNumScc + 
            ((n - 1) * inverse((((k * k) % MOD) * k) % MOD)) % MOD + 1
            - ((3 * n - 2) * inverse(k)) % MOD
        );

    if(expecNumScc < 0) expecNumScc += MOD;
    printf("%lld\n", expecNumScc);

    return 0;
}
