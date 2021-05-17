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
        long long n;
        cin >> n;

        if(n % 2050) {
            cout << "-1\n";
            continue;
        }

        n /= 2050;

        int dig_sum = 0;
        while(n) {
            dig_sum += n % 10;
            n /= 10;
        }

        cout << dig_sum << "\n";
    }


    return 0;
}