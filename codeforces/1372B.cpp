#include<iostream>

using namespace std;

int n;

void solve() {

    if(n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << "\n";
        return;
    }

    for(int i = 3;i * i <= n;i += 2) {
        if(n % i == 0) {
            int common = n / i;
            cout << common << " " << n - common << "\n";
            return;
        }
    }

    cout << "1 " << n - 1 << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        cin >> n;
        solve();
    }
    return 0;
}