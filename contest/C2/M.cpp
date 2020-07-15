#include<iostream>
#include<vector>

using namespace std;

void computePrefix(const string &s, vector<int> &pi) {
    int n = s.size();
    pi.clear();
    pi.resize(n);

    pi[0] = 0;
    for(int i = 1;i < n;i++) {
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if(s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
}

void solve(const string &s) {
    int n = s.size(), maxVal;
    vector<int> pi;

    computePrefix(s, pi);
    
    maxVal = 0;
    for(int i = 1;i < n - 1;i++)
        maxVal = max(maxVal, pi[i]);

    int ans = pi[n - 1];
    while(ans > 0) {
        if(ans <= maxVal) {
            cout << s.substr(0, ans) << "\n";
            return;
        }
        ans = pi[ans - 1];
    }

    cout << "Just a legend\n";
}

int main() {

    string s;
    cin >> s;
    solve(s);

    return 0;
}