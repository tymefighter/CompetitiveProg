#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];

        int idx = 0;
        while(idx < n - 1 && k > 0) {
            while(a[idx] > 0 && k > 0) {
                a[idx] --;
                a[n - 1] ++;
                k --;
            }

            idx ++;
        }

        for(int x : a) cout << x << " ";
        cout << "\n";
    }

    return 0;
}