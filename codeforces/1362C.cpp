#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long n;

void solve() {
    int m = static_cast<int>(log2(n)) + 1;
    vector<long long> val(m + 1);

    val[0] = 1;
    for(int i = 1;i <= m;i++)
        val[i] = 2 * val[i - 1] + 1;

    long long ans = 0;
    for(long long i = 0;(1ll << i) <= static_cast<long long>(n);i++) {
        if((1ll << i) & n)
            ans += val[i];            
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> n;
        solve();
    }

    return 0;
}