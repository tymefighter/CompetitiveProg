#include <iostream>
#include <vector>

using namespace std;

const int N = 105;
int n, a[N], d[N];

void compute_depth(int l, int r, int depth) {
    int max_idx = l;
    
    for(int i = l + 1;i <= r;i++)
        if(a[i] > a[max_idx]) max_idx = i;

    d[max_idx] = depth;
    if(l < max_idx) compute_depth(l, max_idx - 1, depth + 1);
    if(r > max_idx) compute_depth(max_idx + 1, r, depth + 1);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        scanf("%d ", &n);
        for(int i = 0;i < n;i++) scanf("%d ", &a[i]);

        compute_depth(0, n - 1, 0);
        for(int i = 0;i < n;i++) printf("%d ", d[i]);
        printf("\n");
    }

    return 0;
}