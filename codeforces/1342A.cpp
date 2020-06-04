#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t --) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << abs(y - x) * a + (2 * a < b ? 2 * a : b) * min(x, y) << "\n";
    }

    return 0;
}