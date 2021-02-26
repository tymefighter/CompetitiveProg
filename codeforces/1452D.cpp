#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long fibonacci(int n) {
    if(n == 1 || n == 2) return 1;

    long long fib = 1, prevFib = 1;
    for(int i = 3;i <= n;i++) {
        long long temp = prevFib;
        prevFib = fib;
        fib = (fib + temp) % MOD;
    }

    return fib;
}

long long binaryExp(long long a, long long n) {
    long long ans = 1;
    while(n) {
        if((n & 1) != 0)
            ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        n /= 2;
    }
    return ans;
}

long long solve(int n) {
    long long numWays = fibonacci(n);
    long long modInv = binaryExp(binaryExp(2, n), MOD - 2);
    long long ans = (numWays * modInv) % MOD;

    if(ans < 0) ans += MOD;

    return ans;
}

int main() {

    int n;
    scanf("%d ", &n);
    printf("%lld\n", solve(n));

    return 0;
}
