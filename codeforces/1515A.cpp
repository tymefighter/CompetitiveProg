#include <iostream>
#include <algorithm>

using namespace std;

int w[100];

int main() {

    int t;
    cin >> t;

    while(t --) {
        int n, x, sum_value = 0;
        cin >> n >> x;

        for(int i = 0;i < n;i++) {
            cin >> w[i];
            sum_value += w[i];
        }

        if(sum_value == x) {
            cout << "NO\n";
            continue;
        }

        sort(w, w + n);

        int idx = -1;
        sum_value = 0;

        cout << "YES\n";
        for(int i = 0;i < n;i++) {
            if(sum_value + w[i] == x) {
                idx = i;
                continue;
            }

            cout << w[i] << " ";
            sum_value += w[i];
        }
        if(idx != -1) cout << w[idx];
        cout << "\n";
    }

    return 0;
}