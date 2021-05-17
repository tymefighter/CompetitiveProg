#include <iostream>
#include <cmath>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline bool is_perfect_square(int x) {
    int y = sqrt(x);
    return x == y * y;
}

int main() {
    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n;
        cin >> n;

        if(
            ((n & 1) == 0 && is_perfect_square(n >> 1))
            ||
            ((n & 3) == 0 && is_perfect_square(n >> 2))
        )   cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}