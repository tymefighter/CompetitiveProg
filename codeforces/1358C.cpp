#include<iostream>

using namespace std;

long long x1, x2, y1, y2;

long long computeAns() {
    long long n1 = y2 - y1 + 1, n2 = x2 - x1 + 1;
    if(n2 >= n1)
        return (n1 - 2) * (n1 - 1) + (n2 - n1 + 1) * (n1 - 1) + 1;
    else
        return (n2 - 2) * (n2 - 1) + (n1 - n2 + 1) * (n2 - 1) + 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t --) {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        printf("%lld\n", computeAns());
    }

    return 0;
}