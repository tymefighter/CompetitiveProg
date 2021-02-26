#include <iostream>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        int planet_x, planet_y;
        cin >> planet_x >> planet_y;

        int num_up = 0, num_down = 0, num_left = 0, num_right = 0;
        string s;

        cin >> s;
        for(char c : s) {
            if(c == 'U') num_up ++;
            else if(c == 'D') num_down ++;
            else if(c == 'L') num_left ++;
            else if(c == 'R') num_right ++;
        }

        int diff_x = (num_right - num_left) - planet_x;
        int diff_y = (num_up - num_down) - planet_y;
        bool satisfy_x, satisfy_y;

        if(diff_x >= 0) satisfy_x = (num_right >= diff_x);
        else if(diff_x < 0) satisfy_x = (num_left >= -diff_x);

        if(diff_y >= 0) satisfy_y = (num_up >= diff_y);
        else if(diff_y < 0) satisfy_y = (num_down >= -diff_y);

        if(satisfy_x && satisfy_y) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
