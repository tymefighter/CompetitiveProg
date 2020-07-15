#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
string str, s;
vector<int> pi;

void computePrefix() {
    pi.clear();
    pi.resize(s.size());

    pi[0] = 0;
    for(int i = 1;i < pi.size();i++) {
        int j = pi[i - 1];

        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if(s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
}

void solve() {
    computePrefix();

    int val = 0;
    for(int i = n + 1;i <= 2 * n;i++)
        val = max(val, pi[i]);

    string ans = str.substr(0, val);
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        string strRev;
        cin >> str;
        n = str.size();
        strRev = str;
        reverse(strRev.begin(), strRev.end());
        s = str + "#" + strRev;
        solve();
    }

    return 0;
}