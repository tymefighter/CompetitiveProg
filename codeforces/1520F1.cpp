#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, k;

int main() {

    int t;
    cin >> n >> t;
    cin >> k;

    int low = 1, high = n, ans_idx = n;

    while(low <= high) {
        int mid = (low + high) >> 1;

        cout << "? " << 1 << " " << mid << endl;

        int x;
        cin >> x;
        x = (mid - x);

        if(x >= k) {
            ans_idx = min(ans_idx, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << "! " << ans_idx << endl;

    return 0;
}