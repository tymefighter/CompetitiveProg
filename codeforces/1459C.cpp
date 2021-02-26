#include <iostream>

using namespace std;

inline long long gcd(long long a, long long b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {

    int n, m;
    scanf("%d %d ", &n, &m);

    long long firstValue, gcdRest = 0;
    scanf("%lld ", &firstValue);

    for(int i = 1;i < n;i++) {
        long long a;
        scanf("%lld ", &a);
        gcdRest = gcd(gcdRest, a - firstValue);
    }
    gcdRest = abs(gcdRest);

    for(int i = 0;i < m;i++) {
        long long b;
        scanf("%lld ", &b);
        printf("%lld ", gcd(firstValue + b, gcdRest));
    }
    printf("\n");

    return 0;
}

