#include<iostream>

using namespace std;

long long binaryExp(long long x, long long n, long long mod) {
    if(n == 0)
        return 1;
    else if(n % 2 == 1) return (binaryExp(x, n - 1, mod) * x) % mod;
    else {
        long long val = binaryExp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

int main() {
    long long x, n, mod;

    cin >> x >> n >> mod;
    cout << binaryExp(x, n, mod) << "\n";

    return 0;
}