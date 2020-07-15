#include<iostream>
#include<algorithm>

using namespace std;

const int N = static_cast<int>(2e5 + 5);
int n, k, a[N], w[N];

void readInput() {
    scanf("%d %d ", &n, &k);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
    for(int i = 0;i < k;i++)
        scanf("%d ", &w[i]);
}

void solve() {
    sort(a, a + n);
    sort(w, w + k);

    long long ans = 0;
    for(int i = 0;i < k;i++) {
        ans += a[n - i - 1];
        w[i] --;
        if(w[i] == 0)
            ans += a[n - i - 1];
    }

    reverse(w, w + k);
    int idx = 0;
    for(int i = 0;i < k;i++) {
        if(w[i] == 0)
            break;
        ans += a[idx];
        idx += w[i];
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        solve();
    }

    return 0;
}