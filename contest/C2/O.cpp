#include<iostream>
#include<vector>

using namespace std;

void buildPrefix(const string &s, vector<int> &pi) {
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
    vector<int> pi;
    buildPrefix(s, pi);
    int n = s.size();
    int k = n - pi[n - 1];

    cout << (n % k == 0 ? k : n) << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        if(i)
            cout << "\n";
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}