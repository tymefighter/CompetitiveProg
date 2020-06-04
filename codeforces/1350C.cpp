#include<iostream>
#include<map>

using namespace std;

const int N = static_cast<int>(1e5) + 5;
int n, a[N];
int gcd_pre[N], gcd_suff[N];

void readInput() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
}

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

void solve() {
    gcd_pre[0] = a[0];
    for(int i = 1;i < n;i++)
        gcd_pre[i] = gcd(gcd_pre[i - 1], a[i]);

    gcd_suff[n - 1] = a[n - 1];
    for(int i = n - 2;i >= 0;i--)
        gcd_suff[i] = gcd(gcd_suff[i + 1], a[i]);

    long long ans = gcd_suff[1];

    for(int i = 1;i < n;i++) {
        int gcd_exclude;
        if(i == n - 1)
            gcd_exclude = gcd_pre[n - 2];
        else
            gcd_exclude = gcd(gcd_pre[i - 1], gcd_suff[i + 1]);
        
        ans = lcm(ans, gcd_exclude);
    }

    printf("%lld\n", ans);
}

int main() {
    readInput();
    solve();
    return 0;
}