#include<iostream>

using namespace std;

int main() {

    int t;
    long long a, b, n, m;

    scanf("%d ", &t);
    while(t --) {
        scanf("%lld %lld %lld %lld ", &a, &b, &n, &m);
        if(a + b >= n + m && min(a, b) >= m)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}