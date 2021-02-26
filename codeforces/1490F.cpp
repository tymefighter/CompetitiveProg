#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000;
int n, a[N];
int m, count_arr[N], prefix_sum[N], total_sum;

void read_input() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++) scanf("%d ", &a[i]);
}

void build_count_arr() {
    sort(a, a + n);

    int curr_count = 0;
    m = 0;
    for(int i = 0;i < n;i++) {
        curr_count ++;

        if(i == n - 1 || a[i] != a[i + 1]) {
            count_arr[m ++] = curr_count;
            curr_count = 0;
        }
    }
}

void build_sort_sum() {
    sort(count_arr, count_arr + m);

    prefix_sum[0] = count_arr[0];
    for(int i = 1;i < m;i++)
        prefix_sum[i] = prefix_sum[i - 1] + count_arr[i];

    total_sum = prefix_sum[m - 1];
}

int binary_search(int ct) {
    int low = 0, high = m - 1, ans_idx = -1;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(count_arr[mid] < ct) {
            ans_idx = max(ans_idx, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }

    ans_idx ++;
    return total_sum - (m - ans_idx) * static_cast<long long>(ct);
}

void solve() {
    build_count_arr();
    build_sort_sum();

    int min_ops = n;
    for(int ct = 0;ct <= n;ct++) {
        int curr_val = binary_search(ct);
        min_ops = min(min_ops, curr_val);
    }
    
    printf("%d\n", min_ops);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}
