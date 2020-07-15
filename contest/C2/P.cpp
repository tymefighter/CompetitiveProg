#include<iostream>
#include<vector>

using namespace std;

const int N = 50005, p = 29;
const long long m = 1000000007;

int n;
string s;
long long h[N], pInvPow[N];

long long binaryExp(long long x, long long l, long long mod) {
    if(l == 0)
        return 1;
    else if(l % 2 == 1)
        return (binaryExp(x, l - 1, mod) * x) % mod;
    else {
        long long val = binaryExp(x, l / 2, mod);
        return (val * val) % mod;
    }
}

int char2int(char c) {return c - 'A' + 1;}

void computeHashPrefix() {
    long long pInv = binaryExp(p, m - 2, m), pw = p;
    pInvPow[0] = 1;
    h[0] = char2int(s[0]);

    for(int i = 1;i < n;i++) {
        h[i] = (h[i - 1] + char2int(s[i]) * pw) % m;
        pInvPow[i] = (pInvPow[i - 1] * pInv) % m;
        pw = (pw * p) % m;
    }
}

long long computeHashSubstr(int i, int j) {
    long long val = (h[j] - (i > 0 ? h[i - 1] : 0)) % m;
    val = (val * pInvPow[i]) % m;
    if(val < 0)
        val += m;
    return val;
}

void solve() {
    computeHashPrefix();
    int l1 = 0, r1 = 0, l2 = n - 1, r2 = n - 1, ans = 0;
    bool complete = false;

    while(r1 < l2) {
        if(computeHashSubstr(l1, r1) == computeHashSubstr(l2, r2)) {
            ans += 2;
            if(l2 == r1 + 1) {
                complete = true;
                break;
            }
            r1 = l1 = r1 + 1;
            l2 = r2 = l2 - 1;
        }
        else {
            r1 ++;
            l2 --;
        }
    }

    if(!complete)
        ans ++;

    cout << ans << "\n";
}

int main() {
    int t;

    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> s;
        n = s.size();
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}