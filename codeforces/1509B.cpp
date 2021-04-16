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

        string s;
        cin >> s;

        int numT = 0, numTM = 0, numTMT = 0;
        bool not_possible = false;

        for(int i = 0;i < n;i++) {
            if(s[i] == 'T') {
                if(numTM > 0) {
                    numTM --;
                    numTMT ++;
                }
                else numT ++;
            }
            else {
                if(numT == 0) {
                    if(numTMT == 0) {
                        not_possible = true;
                        break;
                    }
                    else {
                        numTM += 2;
                        numTMT --;
                    }
                }
                else {
                    numTM ++;
                    numT --;
                }
            }
        }

        if(not_possible || numT > 0 || numTM > 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}