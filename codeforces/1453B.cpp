#include <iostream>

using namespace std;

const int N = 200005;
int n;
long long a[N];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%lld ", &a[i]);
}

void solve() {
    long long sumDiff = 0, ans;
    for(int i = 1;i < n;i++)
        sumDiff += abs(a[i] - a[i - 1]);

    ans = min(
        sumDiff - abs(a[0] - a[1]), 
        sumDiff - abs(a[n - 2] - a[n - 1])
    );

    for(int i = 1;i < n - 1;i++)
        ans = min(
            ans,
            sumDiff - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1])
            + abs(a[i - 1] - a[i + 1])
        );

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

