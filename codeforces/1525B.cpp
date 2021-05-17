#include <iostream>

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
        cin >> n;

        bool sorted = true;
        int first, last, prev, curr;
        cin >> first;
        prev = first;

        for(int i = 1;i < n;i++) {
            cin >> curr;

            if(curr < prev) sorted = false;
            prev = curr;
        }
        last = curr;

        if(sorted) cout << "0\n";
        else {
            if(first == n && last == 1) cout << "3\n";
            else if(first == 1 || last == n) cout << "1\n";
            else cout << "2\n";
        }
    }


    return 0;
}