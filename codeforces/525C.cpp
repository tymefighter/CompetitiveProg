#include <iostream>
#include <map>

using namespace std;

const int N = 100005;
int n;
long long dp[N], a[N];

void read() {
    map<int, int> m;

    cin >> n;
    for(int i = 0;i < n;i++) {
        int l;
        cin >> l;
        if(m.find(l) == m.end())
            m[l] = 1;
        else
            m[l] ++;
    }

    for(auto it = m.rbegin(); it != m.rend();it++) {
        int l = it->first;
        int ct = it->second;

        if(m.find(l - 1) != m.end() && ct % 2 == 1) {
            m[l - 1] ++;
            m[l] --;
        }
    }

    n = 0;
    for(pair<int, int> x : m) {
        x.second /= 2;

        while(x.second --)
            a[n ++] = x.first;
    }
}

void solve() {
    if(n == 0) {
        cout << "0\n";
        return;
    }

    dp[0] = 0;
    dp[1] = a[1] * a[0];
    for(int i = 2;i < n;i++)
        dp[i] = dp[i - 2] + a[i] * a[i - 1];

    cout << dp[n - 1] << "\n";
}

int main() {

    read();
    solve();
    return 0;
}
