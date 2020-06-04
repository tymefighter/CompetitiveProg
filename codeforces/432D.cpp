#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1e5;

string s;
int n, pi[N], numOcc[N + 1];

void compute_prefix_func() {
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

void computeNumOccPrefix() {
    numOcc[0] = 0;
    for(int i = 1;i <= n;i++)
        numOcc[i] = 1;

    for(int i = n;i > 0;i--) {
        if(pi[i - 1] > 0)
            numOcc[pi[i - 1]] += numOcc[i];
    }
}

void solve() {
    compute_prefix_func();
    computeNumOccPrefix();

    int l = n;
    vector<int> len_vals;
    // l: length of prefix of s that matches suffix of s

    while(l > 0) {
        len_vals.push_back(l);
        l = pi[l - 1];
    }
    reverse(len_vals.begin(), len_vals.end());

    cout << len_vals.size() << "\n";
    for(int len : len_vals)
        cout << len << " " << numOcc[len] << "\n";
}

int main() {
    cin >> s;
    n = s.size();
    solve();
    return 0;
}