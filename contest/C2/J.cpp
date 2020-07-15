#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void solve(const string &s) {
    int n = s.size();
    vector<int> dp(n); // dp[i]: length of longest bracketed substring ending at i
    stack<int> st;
    // stack will store the pos of most recent opening bracket
    // that has not yet been closed, also when we encounter
    // excessive closing brackets, we ignore them
    // actuall s looks like: ))).....))))....))))....))))....
    // where ... means bracketed substring and ))) means
    // excessive closing brackets

    int ansLen = 0, ansIdx = -1;
    for(int i = 0;i < n;i++) {
        if(s[i] == '(') {
            dp[i] = 0;
            st.push(i);
        }
        else if(!st.empty()) {
            int openIdx = st.top();
            st.pop();
            dp[i] = (i - openIdx + 1) + (openIdx > 0 ? dp[openIdx - 1] : 0);
            // this means that we consider the shortest bracketed substring
            // ending at i (let it begin at j),
            // then consider the longest one ending at j - 1 (if j - 1 >= 0)
            // clearly both of them are 'disjoint', hence we can add their
            // lengths to get our answer
        }
        else
            dp[i] = 0;

        if(dp[i] > ansLen) {
            ansLen = dp[i];
            ansIdx = i - ansLen + 1;
        }
    }

    if(ansLen == 0) {
        printf("0 1\n");
        return;
    }

    int numOcc = 0;
    for(int i = 0;i < n;i++)
        numOcc += (dp[i] == ansLen ? 1 : 0);

    printf("%d %d\n", ansLen, numOcc);
}

int main() {
    string s;
    cin >> s;
    solve(s);

    return 0;
}