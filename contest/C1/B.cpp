#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5000005;
const long long p = 257, m = 1000000007;

string s, sRev;
int n, palDegree[N];
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

inline int char2int(char c) {return static_cast<unsigned>(c);}

void computeHashPrefix() {
    long long pw = p, pInv = binaryExp(p, m - 2, m);
    pInvPow[0] = 1;
    h[0] = char2int(s[0]);
    hRev[0] = char2int(sRev[0]);

    for(int i = 1;i < n;i++) {
        h[i] = (h[i - 1] + char2int(s[i]) * pw) % m;
        hRev[i] = (hRev[i - 1] + char2int(sRev[i]) * pw) % m;

        pw = (pw * p) % m;
        pInvPow[i] = (pInvPow[i - 1] * pInv) % m;
    }
}

long long computeHashSubstr(long long *a, int i, int j) {
    long long val = ((a[j] - (i > 0 ? a[i - 1] : 0)) * pInvPow[i]) % m;
    
    if(val < 0)
        val += m;
    return val;
}

void solve() {
    computeHashPrefix();
    long long ans = 1;
    palDegree[0] = 0;
    palDegree[1] = 1;

    for(int i = 2;i <= n;i++) {
        int len = i / 2;
        long long h1, h2;
        if(i % 2 == 0) {
            h1 = computeHashSubstr(h, 0, len - 1);
            h2 = computeHashSubstr(hRev, n - i, n - len - 1);
        }
        else {
            h1 = computeHashSubstr(h, 0, len - 1);
            h2 = computeHashSubstr(hRev, n - i, n - len - 2);
        }

        if(h1 == h2)
            palDegree[i] = palDegree[len] + 1;
        else
            palDegree[i] = 0;

        ans += palDegree[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    sRev = s;
    reverse(sRev.begin(), sRev.end());
    n = s.size();

    solve();
    return 0;
}