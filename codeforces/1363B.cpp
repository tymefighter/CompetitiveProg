#include<iostream>

using namespace std;

const int N = 1005, INF = static_cast<int>(1e8);
string s;
int n, pre0[N], pre1[N], suf0[N], suf1[N];

void solve() {
    if(s[0] == '0') {
        pre0[0] = 0;
        pre1[0] = 1;
    }
    else {
        pre0[0] = 1;
        pre1[0] = 0;
    }

    for(int i = 1;i < n;i++) {
        if(s[i] == '0') {
            pre0[i] = pre0[i - 1];
            pre1[i] = pre1[i - 1] + 1;
        }
        else {
            pre0[i] = pre0[i - 1] + 1;
            pre1[i] = pre1[i - 1];
        }
    }

    if(s[n - 1] == '0') {
        suf0[n - 1] = 0;
        suf1[n - 1] = 1;
    }
    else {
        suf0[n - 1] = 1;
        suf1[n - 1] = 0;
    }

    for(int i = n - 2;i >= 0;i--) {
        if(s[i] == '0') {
            suf0[i] = suf0[i + 1];
            suf1[i] = suf1[i + 1] + 1;
        }
        else {
            suf0[i] = suf0[i + 1] + 1;
            suf1[i] = suf1[i + 1];
        }
    }

    int ans = INF;
    for(int i = 0;i < n;i++) {
        int cost = min(
            (i > 0 ? pre0[i - 1] : 0) + (i < n - 1 ? suf1[i + 1] : 0),
            (i > 0 ? pre1[i - 1] : 0) + (i < n - 1 ? suf0[i + 1] : 0)
        );
 
        ans = min(ans, cost);
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t --) {
        cin >> s;
        n = s.size();
        solve();
    }

    return 0;
}