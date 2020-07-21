#include<iostream>
#include<cmath>

using namespace std;

int main() {

    int ct = 0;
    long long n = 2;

    while(ct < 10) {
        long long m = 1 + 8 * n * n;
        long long r = sqrt(m);
        if(r * r != m) {
            n ++;
            continue;
        }

        m = sqrt(m) - 1;
        if(m % 2 == 0) {
            m /= 2;
            printf("%10lld%10lld\n", n, m);
            ct ++;
        }

        n ++;
    }

    return 0;
}