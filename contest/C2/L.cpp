#include<iostream>
#include<algorithm>
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

void numOccOfPrefix(vector<int> &pi, vector<int> &numOcc) {
    int n = pi.size();
    numOcc.clear();
    numOcc.assign(n + 1, 0);

    for(int i = n;i > 0;i--) {
        numOcc[i] ++;
        if(pi[i - 1] > 0)
            numOcc[pi[i - 1]] += numOcc[i];
    }
}

void solve(const string &s) {
    vector<int> pi, numOcc;
    vector<pair<int, int> > ans;
    
    computePrefix(s, pi);
    numOccOfPrefix(pi, numOcc);

    int n = s.size();
    int len = pi[n - 1];

    ans.push_back({n, 1});

    while(len > 0) {
        ans.push_back({len, numOcc[len]});
        len = pi[len - 1];
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(const pair<int, int> &p : ans)
        cout << p.first << " " << p.second << "\n";
}

int main() {

    string s;
    cin >> s;
    solve(s);

    return 0;
}