#include <iostream>

using namespace std;

inline char is_upper(char c) {
    return 'A' <= c && c <= 'Z';
}

int main() {

    int t;
    cin >> t;

    for(int case_num = 1;case_num <= t;case_num ++) {
        int n, k;
        string s; 

        cin >> n >> k;
        cin >> s;

        int curr_score = 0;
        for(int i = 0;i < n / 2;i++)
            curr_score += (s[i] != s[n - i - 1] ? 1 : 0);

        int num_ops = 0;
        if(curr_score < k) num_ops = k - curr_score;
        else if (curr_score > k) {

            for(int i = 0;i < n / 2;i++) {
                if(curr_score > k && s[i] != s[n - i - 1]
                    && (is_upper(s[i]) || is_upper(s[n - i - 1]))) {

                        curr_score --;
                        num_ops ++;
                }
            }

            if(curr_score > k) {
                num_ops += 2 * (curr_score - k);
                curr_score = k;
            }
        }

        printf("Case #%d: %d\n", case_num, num_ops);
    }

    return 0;
}