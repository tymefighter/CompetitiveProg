#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const long long p = 53, m = 1000000007;
const int N = 100005;

string s, sRev;
long long h[N], hRev[N], pInvPow[N];

long long binaryExp(long long x, long long n, long long mod) {
    if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return (binaryExp(x, n - 1, mod) * x) % mod;
    else {
        long long val = binaryExp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

int char2int(char c) {
    if('a' <= c && c <= 'z')
        return c - 'a' + 1;
    return c - 'A' + 27;
}

void computeHashPrefix() {
    long long pw = p, pInv = binaryExp(p, m - 2, m);
    pInvPow[0] = 1;
    
    h[0] = char2int(s[0]);
    hRev[0] = char2int(sRev[0]);

    for(int i = 1;i < s.size();i++) {
        h[i] = (h[i - 1] + char2int(s[i]) * pw) % m;
        hRev[i] = (hRev[i - 1] + char2int(sRev[i]) * pw) % m;

        pInvPow[i] = (pInvPow[i - 1] * pInv) % m;
        pw = (pw * p) % m;
    }
}

long long computeHashSubstr(long long *a, int i, int j) {
    long long val = a[j] - (i > 0 ? a[i - 1] : 0);
    val = (val * pInvPow[i]) % m;
    if(val < 0)
        val += m;
    return val;
}

bool isPalindrome(int i, int j) {
    int n = s.size();
    return computeHashSubstr(h, i, j)
        == computeHashSubstr(hRev, n - j - 1, n - i - 1);
}

void solve() {
    int n = s.size(), i = 0;

    while(i < n) {
        if(isPalindrome(i, n - 1)) {
            cout << s;
            string t = s.substr(0, i);
            reverse(t.begin(), t.end());
            cout << t << "\n";
            return;
        }
        i ++;
    }

    cout << s;
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

int main() {

    while(cin >> s) {
        sRev = s;
        reverse(sRev.begin(), sRev.end());
        computeHashPrefix();
        solve();
    }
    return 0;
}