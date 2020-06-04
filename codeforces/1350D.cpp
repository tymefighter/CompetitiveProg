#include<iostream>
#include<set>

using namespace std;

bool read_solve() {
    int n, k;
    cin >> n >> k;

    if(n == 1) {
        int x;
        cin >> x;
        return x == k;
    }

    int prev_prev, prev;
    cin >> prev_prev >> prev;

    if(n == 2) {
        return (prev_prev >= k && prev >= k) && (prev_prev == k || prev == k);
    }

    bool contains_k = contains_k = (prev_prev == k || prev == k);
    bool found_close_num = (prev >= k && prev_prev >= k);

    for(int i = 2;i < n;i++) {
        int x;
        cin >> x;
        if(x >= k && prev >= k)
            found_close_num = true;
        else if(x >= k && prev_prev >= k)
            found_close_num = true;

        contains_k |= x == k;
        prev_prev = prev;
        prev = x;
    }

    return contains_k && found_close_num;
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        if(read_solve())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}