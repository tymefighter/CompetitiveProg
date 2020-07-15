#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void compute_prefix_func(const string &s, vector<int> &pi) {
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

void getNumOccEachPrefix(const string &s, vector<int> &numOccPreS){
    vector<int> pi;
    int n = s.size();

    compute_prefix_func(s, pi);
    numOccPreS.clear();
    numOccPreS.resize(n + 1);

    numOccPreS[0] = 0;
    for(int i = 1;i <= n;i++)
        numOccPreS[i] = 1;

    for(int i = n;i >= 1;i--) {
        if(pi[i - 1] > 0)
            numOccPreS[pi[i - 1]] += numOccPreS[i];
    }
}

void getSecret(const string &s, string &secret) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string str = s + '#' + rev_s;

    vector<int> numOccPreS, numOccPreStr;
    getNumOccEachPrefix(s, numOccPreS);
    getNumOccEachPrefix(str, numOccPreStr);

    int secret_len = 0;
    for(int i = 1;i <= s.size();i++) {
        int numOccInRev = numOccPreStr[i] - numOccPreS[i];
        if(numOccInRev > 0)
            secret_len = i;
    }

    secret = s.substr(0, secret_len);
    reverse(secret.begin(), secret.end());
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        string s, secret;
        cin >> s;
        getSecret(s, secret);
        cout << secret << "\n";
    }

    return 0;
}