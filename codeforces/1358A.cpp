#include<iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t --) {
        int n, m, ans;
        cin >> n >> m;

        int max_val = max(n, m);
        int min_val = min(n, m);

        ans = min_val;
        if(max_val % 2 == 1) {
            ans = min_val * (max_val / 2) + (min_val % 2 == 1 ? min_val / 2 + 1 : min_val / 2);
        }
        else
            ans = min_val * (max_val / 2);

        cout << ans << "\n";
    }

    return 0;
}