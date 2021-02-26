#include <iostream>

using namespace std;

const int N = 100000;
int n, q, k, a[N];
long long pre_sum[N];

void read_input() {
    scanf("%d %d %d ", &n, &q, &k);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

void compute_prefix() {
    pre_sum[0] = pre_sum[n - 1] = 0; // Not Defined
    for(int i = 1;i < n;i++)
        pre_sum[i] = pre_sum[i - 1] + (a[i + 1] - a[i - 1] - 2);
}

void solve() {
    compute_prefix();
    
    while(q --) {
        int l, r;
        scanf("%d %d ", &l, &r);
        l --, r --;

        if(l == r) printf("%d\n", k - 1);
        else {
            long long result = a[l + 1] - 3ll + k - a[r - 1];

            if(r > l + 1) result += pre_sum[r - 1] - pre_sum[l];
            printf("%lld\n", result);
        }
    }
}

int main() {

    read_input();
    solve();

    return 0;
}
