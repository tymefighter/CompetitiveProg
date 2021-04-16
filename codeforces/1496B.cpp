#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
int a[N];

int ceil_div(int u, int v) {
    return (u + v - 1) / v;
}

bool found_val(int n, int x) {
    for(int i = 0;i < n;i++) if(a[i] == x) return true;
    return false;
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        int n, k;
        scanf("%d %d ", &n, &k);

        for(int i = 0;i < n;i++) scanf("%d ", &a[i]);

        if(k == 0) {
            printf("%d\n", n);
            continue;
        }

        sort(a, a + n);

        bool non_match = false;
        for(int i = 0;i < n;i++) {
            if(a[i] != i) {
                if(found_val(n, ceil_div(i + a[n - 1], 2))) printf("%d\n", n);
                else printf("%d\n", n + 1);
                non_match = true;
                break;
            }
        }

        if(!non_match) printf("%d\n", n + k);
    }

    return 0;
}