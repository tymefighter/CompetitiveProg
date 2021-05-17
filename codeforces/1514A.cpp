#include <iostream>
#include <cmath>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline int square(int x) {return x * x;}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n;
        cin >> n;

        bool not_perf = false;
        for(int i = 0;i < n;i++) {
            int x;
            cin >> x;

            if(square(sqrt(x)) != x) not_perf = true;
        }

        if(not_perf) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}