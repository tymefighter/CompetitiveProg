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

        if(n == 2) {
            cout << "-1\n";
            continue;
        }

        
        int num_fill = 0, nsq = n * n;
        for(int init_curr = 1;init_curr <= 2;init_curr ++) {
            int curr = init_curr;

            while(curr <= nsq) {
                cout << curr << " ";
                curr += 2;
                num_fill ++;

                if(num_fill % n == 0) cout << "\n";
            }
        }
    }

    return 0;
}