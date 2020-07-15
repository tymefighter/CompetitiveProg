#include<iostream>

using namespace std;

const int M = 100005, N = 15;
int m, n, dp[M];
string s, b[N];

/*

    Very good observation: -
    - dp[i] <= dp[i - 1] + 1
    - we must check only those strings that end at i
    for computing dp[i]

*/

void readInput() {
    cin >> s;
    m = s.size();
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> b[i];
}

// check if s[i - b[j].size() + 1 .. i] == b[j]
bool checkEqual(int i, int j) {
    int idx = i - b[j].size() + 1;

    for(int k = 0;k < b[j].size();k++) {
        if(s[idx + k] != b[j][k])
            return false;
    }

    return true;
}

void solve() {
    int len = 0, pos = 0;
    for(int i = 0;i < m;i++) {
        
        dp[i] = (i > 0 ? dp[i - 1] : 0) + 1;

        for(int j = 0;j < n;j++) {
            if((i > 0 ? dp[i - 1] : 0) + 1 < b[j].size())   
                continue;

            if(checkEqual(i, j))
                dp[i] = min(dp[i], static_cast<int>(b[j].size()) - 1);
        }

        if(dp[i] > len) {
            len = dp[i];
            pos = i - len + 1;
        }
    }

    cout << len << " " << pos << "\n";
}

int main() {

    readInput();
    solve();

    return 0;
}