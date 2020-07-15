#include<iostream>
#include<cstring>

using namespace std;

const int N = 5005, p1 = 29, p2 = 31;
const long long m1 = 1000000007, m2 = 1000000009;

// dp[l][i] = max k value of s[i..i + l - 1]
int n, dp[N][N], ans[N];
char s[N], sRev[N];
long long pInvPow1[N], pInvPow2[N];
long long h1[N], h2[N], hRev1[N], hRev2[N];

void readInput() {
    scanf("%s ", s);
    n = strlen(s);
    for(int i = 0;i < n;i++)
        sRev[i] = s[n - i - 1];
}

long long binaryExp(long long x, long long m, long long mod) {
    if(m == 0)
        return 1;
    else if(m % 2 == 1)
        return (binaryExp(x, m - 1, mod) * x) % mod;
    else {
        long long val = binaryExp(x, m / 2, mod);
        return (val * val) % mod;
    }
}

inline int char2int(char c) {return c - 'a' + 1;}

void computeHashPrefix() {
    long long pw1 = p1, pw2 = p2;
    long long pInv1 = binaryExp(p1, m1 - 2, m1);
    long long pInv2 = binaryExp(p2, m2 - 2, m2);
    
    h1[0] = h2[0] = char2int(s[0]);
    hRev1[0] = hRev2[0] = char2int(sRev[0]);
    pInvPow1[0] = pInvPow2[0] = 1;

    for(int i = 1;i < n;i++) {
        h1[i] = (h1[i - 1] + char2int(s[i]) * pw1) % m1;
        h2[i] = (h2[i - 1] + char2int(s[i]) * pw2) % m2;

        hRev1[i] = (hRev1[i - 1] + char2int(sRev[i]) * pw1) % m1;
        hRev2[i] = (hRev2[i - 1] + char2int(sRev[i]) * pw2) % m2;

        pInvPow1[i] = (pInvPow1[i - 1] * pInv1) % m1;
        pInvPow2[i] = (pInvPow2[i - 1] * pInv2) % m2;

        pw1 = (pw1 * p1) % m1;
        pw2 = (pw2 * p2) % m2;
    }
}

pair<long long, long long>
hashSubstr(long long *a, long long *b, int i, int j) {
    long long val1 = (a[j] - (i > 0 ? a[i - 1] : 0)) % m1;
    val1 = (val1 * pInvPow1[i]) % m1;
    if(val1 < 0)
        val1 += m1;
    
    long long val2 = (b[j] - (i > 0 ? b[i - 1] : 0)) % m2;
    val2 = (val2 * pInvPow2[i]) % m2;
    if(val2 < 0)
        val2 += m2;

    return {val1, val2};
}

bool isPalindrome(int i, int j) {
    return
    hashSubstr(h1, h2, i, j) == hashSubstr(hRev1, hRev2, n - j - 1, n - i - 1);
}

void solve() {

    for(int i = 0;i <= n;i++)
        ans[i] = 0;

    for(int i = 0;i < n;i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
        ans[1] ++;
    }

    for(int l = 2;l <= n;l++) {
        for(int i = 0;i + l <= n;i++) {
            if(isPalindrome(i, i + l - 1))
                dp[l][i] = dp[l / 2][i] + 1;
            else
                dp[l][i] = 0;

            ans[dp[l][i]] ++;
        }
    }

    for(int i = n - 1;i >= 1;i--)
        ans[i] += ans[i + 1];

    for(int i = 1;i <= n;i++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    
    readInput();
    computeHashPrefix();
    solve();
    
    return 0;
}