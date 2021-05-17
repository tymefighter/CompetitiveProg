#include <iostream>

using namespace std;

const int N = 2000;
int n, a[N], pre[N];

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void read() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(i == 0) pre[i] = a[i];
        else pre[i] = pre[i - 1] ^ a[i];
    }
}

inline int range_val(int l, int r) {
    return l == 0 ? pre[r] : (pre[r] ^ pre[l - 1]);
}

void solve() {
    if(!pre[n - 1]) {
        cout << "YES\n";
        return;
    }
    else {
        for(int i = 1;i < n - 1;i++) {
            for(int j = i;j < n - 1;j++) {
                if(range_val(0, i - 1) == range_val(i, j) 
                    && range_val(i, j) == range_val(j + 1, n - 1)) {
                        cout << "YES\n";
                        return;
                    }
            }
        }
    }

    cout << "NO\n";
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