#include<iostream>
#include<vector>

using namespace std;

int max_prefix_value(const string &s) {
    int n = s.size(), maxPrefixValue = 0;
    vector<int> pi(n);

    pi[0] = 0;
    for(int i = 1;i < n;i++) { 
        int j = pi[i - 1];

        while(j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if(s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;

        maxPrefixValue = max(maxPrefixValue, pi[i]);
    }

    return maxPrefixValue;
}

int numDistSubst(const string &s) {
    int n = s.size(), numDist = 0;

    for(int i = 0;i < n;i++)
        numDist += i + 1 - max_prefix_value(s.substr(0, i + 1));

    return numDist;
}

int main() {

    string s;
    cin >> s;
    cout << numDistSubst(s) << "\n";
    return 0;
}