#include<iostream>
#include<cmath>

using namespace std;

long long n;

int solve() {
    long long h = (sqrt(24 * n + 1) - 1) / 6, num = 0;
    while(h > 0) {
        num += 1;
        long long numCardUsed = (3 * h * h + h) / 2;
        n -= numCardUsed;
        h = (sqrt(24 * n + 1) - 1) / 6;
    }

    return num;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t --) {
        scanf("%lld", &n);
        cout << solve() << "\n";
    }

    return 0;
}