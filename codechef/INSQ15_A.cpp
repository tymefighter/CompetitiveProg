#include<iostream>

using namespace std;

const long long mod1 = 1000000007, mod2 = 1000000009;
const int p1 = 31, p2 = 37;
const int N = 5000009;

long long bin_exp(long long x, long long n, const long long &mod) {
    if(n == 0)
        return 1;
    else if(n % 2)
        return (bin_exp(x, n - 1, mod) * x) % mod;
    else {
        long long val = bin_exp(x, n / 2, mod);
        return (val * val) % mod;
    }
}

const long long p1_inv = bin_exp(p1, mod1 - 2, mod1);
const long long p2_inv = bin_exp(p2, mod2 - 2, mod2);

int n;
char s[N];
long long hp1[N], hp2[N], inv_pw1[N], inv_pw2[N];

void readInput() {
    fgets(s, N, stdin);
    
    n = 0;
    while(s[n] != '\0' && s[n] != '\n')
        n ++;
}

int char2int(char c) {return (c - 'a') + 1;}

void build_hash_prefix() {
    long long pw1 = 1, pw2 = 1;

    for(int i = 0;i < n;i++) {
        hp1[i] = ((i > 0 ? hp1[i - 1] : 0) + char2int(s[i]) * pw1) % mod1;
        hp2[i] = ((i > 0 ? hp2[i - 1] : 0) + char2int(s[i]) * pw2) % mod2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
        inv_pw1[i] = (i == 0 ? 1 : (inv_pw1[i - 1] * p1_inv) % mod1);
        inv_pw2[i] = (i == 0 ? 1 : (inv_pw2[i - 1] * p2_inv) % mod2);
    }
}

pair<long long, long long> hash_sub(int i, int j) {
    long long val1 = ((hp1[j] - (i > 0 ? hp1[i - 1] : 0)) * inv_pw1[i]) % mod1;
    if(val1 < 0)
        val1 += mod1;
    long long val2 = ((hp2[j] - (j > 0 ? hp2[i - 1] : 0)) * inv_pw2[i]) % mod2;
    if(val2 < 0)
        val2 += mod2;

    return {val1, val2};
}

void solve() {
    int q;
    scanf("%d", &q);
    while(q --) {
        int p;
        scanf("%d", &p);

        int low = 1, high = min(p, n - p), mid, ans = 0;

        while(low <= high) {
            mid = (low + high) >> 1;
            if(hash_sub(0, mid - 1) == hash_sub(p, p + mid - 1)) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        printf("%d\n", ans);
    }
}

int main() {

    readInput();
    build_hash_prefix();
    solve();

    return 0;
}