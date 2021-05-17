#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline long long gcd(long long x, long long y) {
    return (x == 0 ? y : gcd(y % x, x));
}

int main() {

    enable_fast_io();

    int n;
    cin >> n;

    vector<int> ans;
    int prod = 1;
    for(int i = 1;i < n;i++) {
        if(gcd(i, n) == 1) {
            prod = (static_cast<long long>(prod) * i) % n;
            ans.push_back(i);
        }
    }

    cout << (prod == 1 ? ans.size() : ans.size() - 1) << "\n";
    for(int x : ans) {
        if(x == 1 || x != prod) cout << x << " ";
    }
    cout << "\n";

    return 0;
}