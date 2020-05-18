#include<iostream>

using namespace std;

int n;

void solve() {
    cout << "1 1\n";
    if(n == 1)
        return;

    int i = 1, j = 1;
    long long sum_val = 1, val = 1;

    while(sum_val + val <= n) {
        cout << i + 1 << " 2\n"; 
        sum_val += val;
        val ++;
        i ++;
    }

    if(sum_val == n)
        return;

    i --;
    while(sum_val < n) {
        cout << i + 1 << " 1\n";
        sum_val ++;
        i ++;
    }
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> n;
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}