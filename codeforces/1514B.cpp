#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long MOD = 1000000007;

long long binary_exp(
    long long x, 
    long long n,
    long long mod
) {
    if(n == 0) return 1;
    else if(n % 2 == 1) return (binary_exp(x, n - 1, mod) * x) % mod;
    else {
        long long val = binary_exp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n, k;
        cin >> n >> k;
        cout << binary_exp(n, k, MOD) << "\n";
    }

    return 0;
}