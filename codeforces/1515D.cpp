#include <iostream>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 200000;
int n, left_count[N], right_count[N];

void read() {
    int l, r;
    cin >> n >> l >> r;

    for(int i = 0;i < n;i++) left_count[i] = right_count[i] = 0;

    for(int i = 0;i < n;i++) {
        int c;
        cin >> c;
        c --;

        if (i < l) left_count[c] ++;
        else right_count[c] ++;
    }
}

void solve() {
    int cost = 0, left_used = 0, right_used = 0, left = 0, right = 0;
    for(int i = 0;i < n;i++) {
        int ct = min(left_count[i], right_count[i]);
        left_count[i] -= ct;
        right_count[i] -= ct;

        cost += left_count[i] / 2 + right_count[i] / 2;

        left_used += left_count[i] / 2;
        left_count[i] %= 2;
        left += left_count[i];

        right_used += right_count[i] / 2;
        right_count[i] %= 2;
        right += right_count[i];
    }

    if(left == right) cost += left;
    else if(left < right) {
        cost += left;
        right -= left;

        cost += min(right, 2 * left_used) / 2;
        right -= min(right, 2 * left_used);
        cost += right;
    }
    else {
        cost += right;
        left -= right;

        cost += min(left, 2 * right_used) / 2;
        left -= min(left, 2 * right_used);
        cost += left;
    }

    cout << cost << "\n";
}

int main() {
    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        read();
        solve();
    }

    return 0;
}