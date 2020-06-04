#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
}

void solve() {

    sort(a, a + n);

    int ans = 1;
    for(int i = 0;i < n;i++) {
        if(i + 1 >= a[i])
            ans = i + 2;
    }

    cout << ans << "\n";
}

int main() {

    int t;
    cin >> t;

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}