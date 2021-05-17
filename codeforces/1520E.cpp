#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m;
vector<int> pos;

void read() {
    pos.clear();
    cin >> n;

    int num_sheep = 0;
    for(int i = 0;i < n;i++) {
        char c;
        cin >> c;

        if(c == '*') {
            pos.push_back(i - num_sheep);
            num_sheep ++;
        }
    }

    m = pos.size();
}

int b_search(int x) {
    int low = 0, high = m - 1, ans_idx = -1;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(pos[mid] <= x) {
            ans_idx = max(ans_idx, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return ans_idx;
}

const long long INF = 1e17;

void solve() {
    if(m == 0) {
        cout << "0\n";
        return;
    }

    vector<long long> pre_sum(m), suf_sum(m);

    pre_sum[0] = pos[0];
    for(int i = 1;i < m;i++) pre_sum[i] = pre_sum[i - 1] + pos[i];

    suf_sum[m - 1] = pos[m - 1];
    for(int i = m - 2;i >= 0;i--) suf_sum[i] = suf_sum[i + 1] + pos[i];

    long long ans = INF;
    for(int i = 0;i + pos.size() <= n;i++) {
        int idx = b_search(i);

        long long curr;
        if(idx == -1) curr = suf_sum[0] - m * (long long) i;
        else if(idx == m - 1) curr = m * (long long) i - pre_sum[m - 1];
        else {
            curr = (idx + 1) * (long long) i - pre_sum[idx]
                + suf_sum[idx + 1] - (m - idx - 1) * (long long) i;
        }

        ans = min(ans, curr);
    }

    cout << ans << "\n";
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