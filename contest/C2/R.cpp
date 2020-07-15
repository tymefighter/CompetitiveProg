#include<iostream>

using namespace std;

const int N = 200005;
const long long INF = static_cast<long long>(1e15);

int n, w, m;
int a[N], b[N];
int pi[2 * N];
long long d[2 * N];

void readInput() {
    scanf("%d %d ", &n, &w);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
    for(int i = 0;i < w;i++)
        scanf("%d ", &b[i]);
}

void computePrefix() {
    pi[0] = 0;
    for(int i = 1;i < m;i++) {
        int j = pi[i - 1];
        
        while(j > 0 && d[j] != d[i])
            j = pi[j - 1];

        if(d[j] == d[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
}

void solve() {
    if(n < w) {
        printf("0\n");
        return;
    }
    else if(w == 1) {
        printf("%d\n", n);
        return;
    }

    n --, w --;
    for(int i = 0;i < w;i++)
        d[i] = b[i + 1] - b[i];

    d[w] = -INF;
    for(int i = 0;i < n;i++)
        d[w + 1 + i] = a[i + 1] - a[i];

    m = w + 1 + n;
    computePrefix();

    int ans = 0;
    for(int i = w + 1;i < m;i++)
        ans += (pi[i] == w ? 1 : 0);

    printf("%d\n", ans);
}

int main() {

    readInput();
    solve();

    return 0;
}