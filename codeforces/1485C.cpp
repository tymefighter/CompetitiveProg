#include <iostream>

using namespace std;

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        long long x, y;
        scanf("%lld %lld ", &x, &y);

        long long num_pairs = 0;
        for(long long k = 1;k * k <= x;k ++)
            num_pairs += max(min(x / k - 1, y) - k, 0ll);

        printf("%lld\n", num_pairs);
    }

    return 0;
}
