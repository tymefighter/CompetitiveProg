#include <iostream>

using namespace std;

const int N = 1005;
int n, m, a[N][N], pre[N][N];

int sum_val(int r1, int c1, int r2, int c2) {
    return pre[r2][c2]
        - (r1 > 0 ? pre[r1 - 1][c2] : 0)
        - (c1 > 0 ? pre[r2][c1 - 1] : 0 )
        + (r1 > 0 && c1 > 0 ? pre[r1 - 1][c1 - 1] : 0);
}

bool is_all_ones(int r1, int c1, int r2, int c2) {
    return sum_val(r1, c1, r2, c2) 
        == (r2 - r1 + 1) * (c2 - c1 + 1);
}

int get_top(int i, int j) {
    int low = 0, high = i, res = i;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(is_all_ones(mid, j, i, j)) {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return res;
}

int get_bottom(int i, int j) {
    int low = i, high = n - 1, res = i;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(is_all_ones(i, j, mid, j)) {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return res;
}

int get_left(int i, int j) {
    int low = 0, high = j, res = j;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(is_all_ones(i, mid, i, j)) {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return res;
}

int get_right(int i, int j) {
    int low = j, high = m - 1, res = j;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(is_all_ones(i, j, i, mid)) {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return res;
}

long long solve() {
    long long ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 0) continue;

            long long top = i - get_top(i, j) + 1;
            long long right = get_right(i, j) - j + 1;
            long long left = j - get_left(i, j) + 1;
            long long bottom = get_bottom(i, j) - i + 1;

            long long curr = (min(top, right / 2) + min(top / 2, right)
                + min(top, left / 2) + min(top / 2, left)
                + min(bottom, right / 2) + min(bottom / 2, right)
                + min(bottom, left / 2) + min(bottom / 2, left));

            curr -= (top > 1 ? 2 : 0) + (left > 1 ? 2 : 0) + (right > 1 ? 2 : 0)
                + (bottom > 1 ? 2 : 0);

            ans += curr;
        }
    }

    return ans;
}

int main() {

    int t;
    scanf("%d ", &t);

    for(int tc = 1;tc <= t;tc++) {
        scanf("%d %d ", &n, &m);

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf("%d ", &a[i][j]);

                pre[i][j] = a[i][j]
                    + (i > 0 ? pre[i - 1][j] : 0) 
                    + (j > 0 ? pre[i][j - 1] : 0)
                    - (i > 0 && j > 0 ? pre[i - 1][j - 1] : 0);
            }
        }

        printf("Case #%d: %lld\n", tc, solve());
    }

    return 0;
}