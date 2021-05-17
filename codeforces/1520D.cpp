#include <iostream>
#include <map>

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

        map<int, int> count_map;
        for(int i = 0;i < n;i++) {
            int x;
            cin >> x;
            count_map[x - i] ++;
        }

        long long ans = 0;
        for(pair<int, int> key_val : count_map)
            ans += (key_val.second 
                * static_cast<long long>(key_val.second - 1)) / 2;
        
        cout << ans << "\n";
    }

    return 0;
}