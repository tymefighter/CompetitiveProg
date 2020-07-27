#include<iostream>

using namespace std;

const int N = 200005;
int n, a[N];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

void solve() {
    int maxIdx = n - 1, ans = 1;
    for(int i = n - 2;i >= 0;i--) {
        if(a[i] >= a[maxIdx]) {
            if(a[i + 1] != a[maxIdx])
                break;
            maxIdx = i;
        }
        else {
            if(a[i] > a[i + 1])
                break;
        }

        ans ++;
    }

    cout << n - ans << "\n";
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