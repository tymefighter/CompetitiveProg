#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1e7;

class FenwickTree {
    private:

    int n;
    vector<int> b;

    inline int g(int i) {return i & (i + 1);}
    inline int h(int i) {return i | (i + 1);}

    int prefix_sum(int r) {
        int sum_value = 0;

        while(r >= 0) {
            sum_value += b[r];
            r = g(r) - 1;
        }

        return sum_value;
    }

    void update(int i, int x) {
        while(i < n) {
            b[i] += x;
            i = h(i);
        }
    }

    public:

    FenwickTree(const vector<int> &a):
        n(a.size()), b(n, 0) {
            for(int i = 0;i < n;i++) range_update(i, i, a[i]);
        }

    void range_update(int l, int r, int x) {
        update(l, x);
        if(r + 1 < n) update(r + 1, -x);
    }

    inline int point_query(int i) {
        return prefix_sum(i);
    }
};

int n, t;

void solve() {
    FenwickTree ft(vector<int>(n, -INF));

    while(t --) {
        int k;
        cin >> k;

        int low = 0, high = n - 1, ans_idx = n - 1;

        while(low <= high) {
            int mid = (low + high) >> 1;

            int x = ft.point_query(mid);
            if(x < 0) {
                int x_input;
                cout << "? " << 1 << " " << mid + 1 << endl;
                cin >> x_input;

                x_input = mid + 1 - x_input;
                ft.range_update(mid, mid, x_input - x);
                x = x_input;
            }

            if(x >= k) {
                ans_idx = min(ans_idx, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }

        cout << "! " << ans_idx + 1 << endl;
        ft.range_update(ans_idx, n - 1, -1);
    }
}

int main() {

    enable_fast_io();

    cin >> n >> t;
    solve();

    return 0;
}