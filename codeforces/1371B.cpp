#include<iostream>

using namespace std;

int main() {

    int t;
    long long n, r;

    scanf("%d ", &t);
    while(t --) {
        scanf("%lld %lld ", &n, &r);
        long long ans = 0;
        if(r < n)
            ans = (r * (r + 1)) / 2;
        else
            ans = (n * (n - 1)) / 2 + 1;
        printf("%lld\n", ans);
    }

    return 0;
}
