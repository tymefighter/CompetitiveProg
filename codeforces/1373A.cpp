#include<iostream>

using namespace std;

long long a, b, c;

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        scanf("%lld %lld %lld ", &a, &b, &c);
        printf("%d ", (a < c ? 1 : -1));
        printf("%lld\n", (b * a > c ? b : -1));
    }
    return 0;
}