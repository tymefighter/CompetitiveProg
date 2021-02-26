#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;
int n, m, sumA, sumB, a[N], b[N];

void readInput() {
    scanf("%d %d ", &n, &m);

    sumA = sumB = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d ", &a[i]);
        sumA += a[i];
    }
    for(int i = 0;i < m;i++) {
        scanf("%d ", &b[i]);
        sumB += b[i];
    }
}

void solve() {
    sort(a, a + n);
    sort(b, b + m, greater<int>());

    int numPicks = 0;
    int minSize = min(n, m);
    while(sumA <= sumB && numPicks < minSize) {
        sumA += b[numPicks] - a[numPicks];
        sumB += a[numPicks] - b[numPicks];
        numPicks ++;
    }

    if(sumA > sumB) printf("%d\n", numPicks);
    else printf("-1\n");
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
