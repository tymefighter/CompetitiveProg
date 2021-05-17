#include <iostream>

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
        long long r, b, d;
        cin >> r >> b >> d;

        if(r < b) swap(r, b);

        if(r <= b * (d + 1)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}