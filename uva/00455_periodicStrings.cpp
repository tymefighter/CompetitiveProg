#include<iostream>
#include<vector>

using namespace std;

void build_prefix(vector<int> &pi, const string &s) {
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

int getPeriod(const string &s) {
    int n = s.size();
    vector<int> pi;
    build_prefix(pi, s);

    int k = n - pi[n - 1];
    return (n % k == 0 ? k : n);
}

int main() {
    int t;
    string s;

    cin >> t;
    for(int i = 0;i < t;i++) {
        if(i)
            cout << "\n";
        cin >> s;
        cout << getPeriod(s) << "\n";
    }
    return 0;
}