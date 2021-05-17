#include <iostream>
#include <stack>

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

        stack<int> rep;

        while(n) {
            rep.push(n % 10);
            n /= 10;
        }

        int num_prev_dig = rep.size() - 1;

        int front_dig = rep.top();
        bool lesser = false;
        while(!rep.empty()) {
            if(rep.top() > front_dig) break;
            else if(rep.top() < front_dig) {
                lesser = true;
                break;
            }
            
            rep.pop();
        }

        int ans = (lesser ? front_dig - 1 : front_dig)
            + 9 * num_prev_dig;

        cout << ans << "\n";
    }

    return 0;
}