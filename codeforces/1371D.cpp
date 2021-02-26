#include<iostream>

using namespace std;

const int N = 305;
int n, k;
bool a[N][N];

void solve() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            a[i][j] = false;
    }

    int r = 0, c = 0, prev_r = 0;
    for(int i = 0;i < k;i++) {
        a[r][c] = true;
        r ++;
        c ++;

        if(c == n)
            c = 0;

        if(r == n)
            r = 0;

        if(prev_r == r) {
            r ++;
            prev_r ++;
        }
    }

    printf("%d\n", (k % n == 0 ? 0 : 2));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            printf("%d", (a[i][j] ? 1 : 0));
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d ", &t);

    while(t --) {
        scanf("%d %d ", &n, &k);
        solve();
    }

    return 0;
}