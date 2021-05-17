#include <iostream>

using namespace std;

inline int gcd(int x, int y) {
    return x == 0 ? y : gcd(y % x, x);
}

int main() {

    int t;
    cin >> t;

    while(t --) {
        int k;
        cin >> k;

        int x = k, y = 100 - k;
        int g = gcd(x, y);
        x /= g;
        y /= g;

        cout << x + y << "\n";
    }


    return 0;
}