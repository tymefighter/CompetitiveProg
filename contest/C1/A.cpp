#include<iostream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

const long long p = 29, m = 1000000007;

int n;
string line, s;
vector<long long> h, pInvPow;

void readInput() {
    stringstream ss;

    ss.clear();
    ss.str(line);

    s = "";
    while(!ss.eof()) {
        string str;
        ss >> str;
        s.append(str);
    }
    n = s.size();
    
    h.clear();
    pInvPow.clear();
    h.resize(n);
    pInvPow.resize(n);
}

inline int char2int(char c) {return (c - 'A') + 1;}

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

void computeHashPrefix() {
    long long pw = p, pInv = binaryExp(p, m - 2, m);
    pInvPow[0] = 1;
    h[0] = char2int(s[0]);

    for(int i = 1;i < n;i++) {
        h[i] = (h[i - 1] + char2int(s[i]) * pw) % m;
        pInvPow[i] = (pInvPow[i - 1] * pInv) % m;
        pw = (pw * p) % m;
    }
}

long long computeHashSubstr(int i, int j) {
    long long val = ((h[j] - (i > 0 ? h[i - 1] : 0)) * pInvPow[i]) % m;
    if(val < 0)
        val += m;
    return val;
}

void solve() {
    computeHashPrefix();

    int len = 1;
    while(len <= n) {
        map<long long, int> mp;
        for(int i = 0;i + len <= n;i++)
            mp[computeHashSubstr(i, i + len - 1)] ++;
        
        int maxOcc = 0;
        for(auto pr : mp)
            maxOcc = max(maxOcc, pr.second);

        if(maxOcc < 2)
            break;
        
        cout << maxOcc << "\n";
        len ++;
    }
}

int main() {
    int ct = 0;
    while(getline(cin, line)) {
        if(ct)
            cout << "\n";
        readInput();
        solve();
        ct ++;
    }
    return 0;
}