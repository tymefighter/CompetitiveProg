#include <iostream>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100000;
int ans[N];
pair<int, int> h[N];

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n, m, x;
        cin >> n >> m >> x;

        for(int i = 0;i < n;i++) {
            cin >> h[i].first;
            h[i].second = i;
        }
        sort(h, h + n);

        for(int i = 0;i < n;i++) ans[h[i].second] = i % m;

        cout << "YES\n";
        for(int i = 0;i < n;i++) cout << ans[i] + 1 << " ";
        cout << "\n";
    }

    return 0;
}