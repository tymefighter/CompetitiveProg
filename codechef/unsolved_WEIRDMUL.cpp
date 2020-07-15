#include<iostream>
#include<cassert>

using namespace std;

const int N = 100005;
const long long MOD = 998244353;

long long n, x, A;
long long prefixProd[N];

void readInput() {
    scanf("%lld %lld ", &n, &x);
    scanf("%lld ", &A);
    for(int i = 1;i < n;i++) {
        long long x;
        scanf("%lld ", &x);
        assert(A == x);
    }
}

long long binaryExp(long long u, long long m, long long mod) {
    if(m == 0)
        return 1;
    else if(m % 2 == 1)
        return (binaryExp(u, m - 1, mod) * u) % mod;
    else {
        long long val = binaryExp(u, m / 2, mod);
        return (val * val) % mod;
    }
}

long long solve() {
    long long pwX = x;
    for(int i = 0;i < n;i++) {
        prefixProd[i] = (i > 0 ? prefixProd[i - 1] : 1);

        if(x == 1) {
            long long val = i + 1;
            val = (val * val) % MOD;
            prefixProd[i] = (prefixProd[i] * val) % MOD;
            continue;
        }

        long long sqVal = (pwX - 1) % MOD;
        sqVal = (sqVal * sqVal) % MOD;
        
        prefixProd[i] = (prefixProd[i] * sqVal) % MOD;
        pwX = (pwX * x) % MOD;
    }

    long long ans = 1;
    for(int i = 0;i < n;i++)
        ans = (ans * prefixProd[i]) % MOD;

    long long val = (A * (x > 1 ? binaryExp(x - 1, MOD - 2, MOD) : 1)) % MOD;
    val = binaryExp(val, n * (n + 1), MOD);

    ans = (val * ans) % MOD;
    if(ans < 0)
        ans += MOD;

    return ans;
}

int main() {

    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        printf("%lld\n", solve());
    }

    return 0;
}