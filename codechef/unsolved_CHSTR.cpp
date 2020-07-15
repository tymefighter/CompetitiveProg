#include<iostream>
#include<vector>
#include<map>

using namespace std;

const long long p1 = 29, m1 = 1000000007;
const long long p2 = 31, m2 = 1000000009;

const int N = 1005;
const long long MOD = 1000000007;

int n, q;
char s[N];

long long pInvPow1[N], pInvPow2[N], h1[N], h2[N];

vector<int> L;

void readInput() {
    scanf("%d %d ", &n, &q);
    for(int i = 0;i < n;i++)
        scanf("%c ", &s[i]);
}

int char2int(char c) {return c - 'a' + 1;}

void computeHashPrefix() {
    long long pw1 = p1, pw2 = p2;
    long long pInv1 = binaryExp(p1, m1 - 2, m1);
    long long pInv2 = binaryExp(p2, m2 - 2, m2);
    h2[0] = h1[0] = char2int(s[0]);
    pInvPow2[0] = pInvPow1[0] = 1;

    for(int i = 1;i < n;i++) {
        h1[i] = (h1[i - 1] + char2int(s[i]) * pw1);
        h2[i] = (h2[i - 1] + char2int(s[i]) * pw2);
        pw1 = (pw1 * p1) % m1;
        pw2 = (pw2 * p2) % m2;
        pInvPow1[i] = (pInvPow1[i - 1] * pInv1) % m1;
        pInvPow2[i] = (pInvPow2[i - 1] * pInv2) % m2;
    }
}

pair<long long, long long> computeHashSubstr(int i, int j) {
    long long val1 = (((h1[j] - (i > 0 ? h1[i - 1] : 0)) % m1)
        * pInvPow1[i]) % m1;

    long long val2 = (((h2[j] - (i > 0 ? h2[i - 1] : 0)) % m2)
        * pInvPow2[i]) % m2;

    if(val1 < 0)
        val1 += m1;
    if(val2 < 0)
        val2 += m2;

    return {val1, val2};
}

void generateSubst() {
    L.clear();

    for(int l = 1;l <= n;l++) {
        map<pair<long long, long long>, int> mp;

        for(int i = 0;i + l <= n;i++) {
            pair<long long, long long> hsub =
                computeHashSubstr(i, i + l - 1);
            if(mp.find(hsub) == mp.end())
                mp[hsub] = 1;
            else
                mp[hsub] ++; 
        }

        for(auto pr : mp)
            L.push_back(pr.second);
    }

    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
}

long long C[N][N];

void computeDP() {

}

void solve() {
    while(q --) {

    }
}

int main() {

    int t;
    scanf("%d ", &t);
    while(t --) {
        readInput();
        solve();
    }

    return 0;
}