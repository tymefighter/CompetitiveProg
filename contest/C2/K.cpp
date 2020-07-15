#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 2005;
int n;
string s;
bool dp[N][N]; // dp[l][i] = true if s[i..i + l - 1] is a palindrome, else false
vector<pair<int, int> > palindromeSubstrings;

void computeDP() {
    for(int i = 0;i < n;i++)
        dp[1][i] = dp[0][i] = true;

    for(int l = 2;l <= n;l++) {
        for(int i = 0;i + l <= n;i++)
            dp[l][i] = (s[i] == s[i + l - 1]) && (dp[l - 2][i + 1]);
    }
}

// compare based on right end point
bool comp(const pair<int, int> &u, const pair<int, int> &v) {
    return u.second < v.second;
}

int bSearch(int startIdx) {
    int low = 0, high = static_cast<int>(palindromeSubstrings.size());
    int ansIdx = -1;

    while(low <= high) {
        int mid = (low + high) >> 1;
        if(palindromeSubstrings[mid].second < startIdx) {
            ansIdx = max(ansIdx, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ansIdx + 1;
}

void solve() {
    palindromeSubstrings.clear();
    computeDP();
    for(int l = 1;l <= n;l++) {
        for(int i = 0;i + l <= n;i++) {
            if(dp[l][i])
                palindromeSubstrings.push_back({i, i + l - 1});
        }
    }

    sort(palindromeSubstrings.begin(), palindromeSubstrings.end(), comp);

    long long numNonIntersectingPalPairs = 0;
    for(const pair<int, int> &p : palindromeSubstrings)
        numNonIntersectingPalPairs += bSearch(p.first);

    cout << numNonIntersectingPalPairs << "\n";
}

int main() {
    cin >> s;
    n = s.size();
    solve();

    return 0;
}