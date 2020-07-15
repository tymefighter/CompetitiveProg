#include<iostream>

using namespace std;

/*
    UNSOLVED
*/

long n, m;

void solve() {
    long long val = 0;
    for(int i = 1;i <= min(n, m);i++) {
        cout << (i * i) << " " << (n - (i - 1)) * (m - (i - 1)) << " ";
        cout << (n - (i - 1)) * (m - (i - 1)) * i * i << "\n";
        val += (n - (i - 1)) * (m - (i - 1)) * i * i;
    }

    for(int i = 1;i <= (min(n, m) + 1) / 2;i++) {
        cout << (2 * i * i) << " " << (n + 1 - 2 * i) * (m + 1 - 2 * i) << " ";
        cout << (n + 1 - 2 * i) * (m + 1 - 2 * i) * (2 * i * i) << "\n";
        val += (n + 1 - 2 * i) * (m + 1 - 2 * i) * (2 * i * i) ;
    }

    cout << val << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        cin >> n >> m;
        solve();
    }

    return 0;
}