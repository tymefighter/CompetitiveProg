#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 26;
bool seen[N];

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int n;
        cin >> n;

        for(int i = 0;i < N;i++) seen[i] = false;

        char prev;
        cin >> prev;
        seen[prev - 'A'] = true;
        bool susp = false;

        for(int i = 1;i < n;i++) {
            char curr;
            cin >> curr;

            if(!susp && seen[curr - 'A'] && curr != prev) susp = true;

            seen[curr - 'A'] = true;
            prev = curr;
        }

        cout << (!susp ? "YES" : "NO") << "\n";
    }

    return 0;
}