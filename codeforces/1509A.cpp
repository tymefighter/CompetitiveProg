#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n;
        vector<int> even, odd;

        cin >> n;
        for(int i = 0;i < n;i++) {
            int a;
            cin >> a;
            if(a & 1) odd.push_back(a);
            else even.push_back(a);
        }

        for(int x : even) cout << x << " ";
        for(int x : odd) cout << x << " ";
        cout << "\n";
    }

    return 0;
}