#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100000;
int n;
string a, b, c;

void read_input() {
    cin >> n;
    cin >> a >> b >> c;
}

int zero_a, zero_b, zero_c;

void solve() {
    zero_a = zero_b = zero_c = 0;
    for(int i = 0;i < 2 * n;i++) {
        if(a[i] == '0') zero_a ++;
        if(b[i] == '0') zero_b ++;
        if(c[i] == '0') zero_c ++;
    }

    bool more_zero;
    string u, v;

    if(zero_a >= n && zero_b >= n) {
        u = a; v = b; more_zero = true;
    }
    else if(zero_b >= n && zero_c >= n) {
        u = b; v = c; more_zero = true;
    }
    else if(zero_c >= n && zero_a >= n) {
        u = c; v = a; more_zero = true;
    }
    else if(zero_a < n && zero_b < n) {
        u = a; v = b; more_zero = false;
    }
    else if(zero_b < n && zero_c < n) {
        u = b; v = c; more_zero = false;
    }
    else {
        u = c; v = a; more_zero = false;
    }

    int i = 0, j = 0;
    while(i < u.size() || j < v.size()) {
        if(i == u.size()) cout << v[j ++];
        else if(j == v.size()) cout << u[i ++];
        else {
            if(more_zero) {
                if(u[i] == '0') {
                    while(j < v.size() && v[j] != '0')
                        cout << v[j ++];

                    j ++;
                }
                
                cout << u[i ++];
            }
            else {
                if(u[i] == '1') {
                    while(j < v.size() && v[j] != '1')
                        cout << v[j ++];

                    j ++;
                }
                
                cout << u[i ++];
            }
        }
    }

    cout << "\n";
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}