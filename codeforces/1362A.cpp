#include<iostream>

using namespace std;

long long a, b;

int solve() {
    int k1 = 0, k2 = 0;

    while(a % 2 == 0) {
        a /= 2;
        k1 ++;
    }

    while(b % 2 == 0) {
        b /= 2;
        k2 ++;
    }

    if(a != b)
        return -1;

    int u = abs(k1 - k2);

    return (u / 3) + (u % 3 != 0 ? 1 : 0);
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> a >> b;
        cout << solve() << "\n";
    }
    return 0;
}