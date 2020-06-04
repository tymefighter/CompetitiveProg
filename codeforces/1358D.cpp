#include<iostream>

using namespace std;

const int INF_IDX = static_cast<int>(1e8);
const int N = 2 * static_cast<int>(2e5) + 5;
int n;
long long a[N], pre[N], pre_val[N], x;

void readInput() {
    scanf("%d %lld", &n, &x);
    for(int i = 0;i < n;i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }

    n += n;
    pre[0] = a[0];
    pre_val[0] = (a[0] * (a[0] + 1)) / 2;
    for(int i = 1;i < n;i++) {
        pre[i] = pre[i - 1] + a[i];
        pre_val[i] = pre_val[i - 1] + (a[i] * (a[i] + 1)) / 2;
    }
}

inline long long rsq(int l, int r) {
    return pre[r] - (l > 0 ? pre[l - 1] : 0);
}

inline long long rsq_val(int l, int r) {
    return pre_val[r] - (l > 0 ? pre_val[l - 1] : 0);
}

int b_search(int idx, long long val) {
    int low = 0, high = idx, mid, ansIdx = INF_IDX;

    while(low <= high) {
        mid = (low + high) >> 1;
        if(rsq(mid, idx) <= val) {
            ansIdx = min(ansIdx, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ansIdx;
}

void solve() {
    long long ans_val = 0;

    for(int i = 0;i < n;i++) {
        if(pre[i] >= x) {
            int left_idx = b_search(i, x);
            long long curr_val;

            if(left_idx == INF_IDX)
                curr_val = x * a[i] - (x * (x - 1)) / 2;
            else {
                long long leftOverDays = x - rsq(left_idx, i);
                curr_val = leftOverDays * a[left_idx - 1] - (leftOverDays * (leftOverDays - 1)) / 2
                    + rsq_val(left_idx, i);
            }

            ans_val = max(ans_val, curr_val);
        }
    }

    printf("%lld\n", ans_val);
}


int main() {

    readInput();
    solve();
    return 0;
}