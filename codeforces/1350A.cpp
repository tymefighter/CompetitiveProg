#include<iostream>

using namespace std;

int n, k;

void solve() {

    int pr = -1;
    long long ansVal = n;

    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            pr = i;
            break;
        }
    }
    if(pr == -1)
        pr = n;

    ansVal += pr;
    k --;
    ansVal += k * 2;
    printf("%lld\n", ansVal);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        scanf("%d %d", &n, &k);
        solve();
    }
    return 0;
}