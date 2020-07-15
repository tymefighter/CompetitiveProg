#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
    Two things to see:

    1.  Does deletion of a repeat cause new repeats to form ?
    A.  No, all repeats after deletion must already be
        present in the string before deletion of the repeat
    
    2.  Total Number of Repeats (a bound) ?
    A.  For every repeat, the first and middle element must
        be the same. Hence, num of repeats:

        numRepeats <= sum over i (ni^2)
            <= (max over i (ni)) * (sum over i (ni))
            <= 10 * n

        where ni = number of occurances of i in the array
    
    Hence, we can generate all repeats by considering
    every pair of similar valued elements in the array
*/

const int N = static_cast<int>(1e5 + 5);
const long long p = 1000000007, m = 1000000009;

int n, a[N];
map<int, vector<int> > occ;
long long h[N], pInvPow[N];
vector<pair<int, int> > repeats;

void readInput() {
    scanf("%d ", &n);

    occ.clear();
    for(int i = 0;i < n;i++) {
        scanf("%d ", &a[i]);
        if(occ.find(a[i]) == occ.end())
            occ[a[i]] = vector<int> ();

        occ[a[i]].push_back(i);
    }
}

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

void computeHashPrefix() {
    long long pw = p, pInv = binaryExp(p, m - 2, m);
    h[0] = a[0];
    pInvPow[0] = 1;

    for(int i = 1;i < n;i++) {
        h[i] = (h[i - 1] + (a[i] * pw) % m) % m;
        pw = (pw * p) % m;
        pInvPow[i] = (pInvPow[i - 1] * pInv) % m;
    }
}

long long computeHashSubstr(int i, int j) {
    long long val = (h[j] - (i > 0 ? h[i - 1] : 0)) % m;
    val = (val * pInvPow[i]) % m;
    if(val < 0)
        val += m;
    return val;
}

void buildAllRepeats() {
    repeats.clear();

    for(const pair<int, vector<int> > &p : occ) {
        const vector<int> &pos = p.second;
        for(int i = 0;i < pos.size();i++) {
            for(int j = i + 1;j < pos.size();j++) {
                int u = pos[i], v = pos[j];
                if(n - v < v - u)
                    continue;
                
                int len = v - u;
                if(computeHashSubstr(u, v - 1)
                    == computeHashSubstr(v, v + len - 1))
                    repeats.push_back({len, u});
            }
        }
    }
}

void solve() {
    computeHashPrefix();
    buildAllRepeats();
    sort(repeats.begin(), repeats.end());

    int l = 0; // left index of the leftover array

    for(const pair<int, int> &repeat : repeats) {
        int len = repeat.first;
        int idx = repeat.second;

        if(idx >= l)
            l = idx + len;
    }

    printf("%d\n", n - l);
    while(l < n) {
        printf("%d ", a[l]);
        l ++;
    }
    printf("\n");
}

int main() {

    readInput();
    solve();

    return 0;
}