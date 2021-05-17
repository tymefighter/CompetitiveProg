#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const long long large_prime = 1847726627;
const int N = 200000;
int n, a[N];

int main() {
    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];

        if(n == 1) {
            cout << "0\n";
            continue;
        }

        cout << (n + 1) / 2 << "\n";
        for(int i = 0;i + 1 < n;i += 2) {
            cout 
                << i + 1 << " " << i + 2 << " " 
                << large_prime << " " << min(a[i], a[i + 1])
                << "\n";

            a[i + 1] = min(a[i], a[i + 1]);
            a[i] = large_prime;
        }

        if(n % 2)
            cout 
                << n - 1 << " " << n << " " 
                << min(a[n - 2], a[n - 1]) << " " << large_prime
                << "\n";
    }

    return 0;
}