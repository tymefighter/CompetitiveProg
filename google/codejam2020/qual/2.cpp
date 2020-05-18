#include<iostream>

using namespace std;

string s;

void solve(int case_num) {

    string ans;
    int curr_depth = 0;

    for(char x : s) {

        int digit = static_cast<int>(x - '0');
        if(curr_depth > digit) {
            while(curr_depth > digit) {
                ans.push_back(')');
                curr_depth --;
            }
        }
        else if(curr_depth < digit) {
            while(curr_depth < digit) {
                ans.push_back('(');
                curr_depth ++;
            }
        }

        ans.push_back(x);
    }

    if(curr_depth > 0) {
        while(curr_depth > 0) {
            ans.push_back(')');
            curr_depth --;
        }
    }

    cout << "Case #" << case_num <<  ": " << ans << "\n";
}

int main() {

    int t;
    cin>>t;
    for(int i = 1;i <= t;i++) {
        cin>>s;
        solve(i);
    }
    return 0;
}