#include<iostream>

using namespace std;

int n, m, k;

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> n >> m >> k;
        int x = min(m, n / k);
        cout << x - ((m - x) / (k - 1) + ((m - x) % (k - 1) == 0 ? 0 : 1)) << "\n";
    }
    return 0;
}