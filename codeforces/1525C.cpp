#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 300005;
pair<pair<int, char>, int> x[N];
int n, ans[N];
char direction[N];

long long m, a[N], times[N];

void read() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        cin >> x[i].first.first;
        x[i].second = i;
        times[i] = -1;
    }

    for(int i = 0;i < n;i++) cin >> x[i].first.second;

    sort(x, x + n);
    for(int i = 0;i < n;i++) {
        a[i] = x[i].first.first;
        direction[i] = x[i].first.second;
    }
}

inline bool is_odd(int x) {return x & 1;}
inline bool is_even(int x) {return !(x & 1);}

void opp_direction_approach() {
    stack<int> right_odd_stack, right_even_stack;
    for(int i = 0;i < n;i++) {
        if(direction[i] == 'R') {
            if(is_odd(a[i])) right_odd_stack.push(i);
            else right_even_stack.push(i);
        }
        else {
            if(is_odd(a[i]) && !right_odd_stack.empty()) {
                times[i] = times[right_odd_stack.top()] = 
                    (a[i] - a[right_odd_stack.top()]) / 2;

                right_odd_stack.pop();
            } 
            else if(is_even(a[i]) && !right_even_stack.empty()) {
                times[i] = times[right_even_stack.top()] = 
                    (a[i] - a[right_even_stack.top()]) / 2;

                right_even_stack.pop();
            }
        }
    }
}

void same_direction(
    vector<int> &left_odd, vector<int> &left_even, 
    vector<int> &right_odd, vector<int> &right_even
) {
    for(int i = 1;i < left_odd.size();i += 2) 
        times[left_odd[i]] = times[left_odd[i - 1]] = 
            a[left_odd[i - 1]] + (a[left_odd[i]] - a[left_odd[i - 1]]) / 2;

    for(int i = 1;i < left_even.size();i += 2) 
        times[left_even[i]] = times[left_even[i - 1]] = 
            a[left_even[i - 1]] + (a[left_even[i]] - a[left_even[i - 1]]) / 2;

    for(int i = right_odd.size() - 2;i >= 0;i -= 2) 
        times[right_odd[i]] = times[right_odd[i + 1]] = 
            m - a[right_odd[i + 1]] + (a[right_odd[i + 1]] - a[right_odd[i]]) / 2;

    for(int i = right_even.size() - 2;i >= 0;i -= 2) 
        times[right_even[i]] = times[right_even[i + 1]] = 
            m - a[right_even[i + 1]] + (a[right_even[i + 1]] - a[right_even[i]]) / 2;
}

void opp_direction_away(
    vector<int> &left_odd, vector<int> &left_even, 
    vector<int> &right_odd, vector<int> &right_even
) {
    if(is_odd(left_odd.size()) && is_odd(right_odd.size())) {
        int p = left_odd.back();
        int q = right_odd.front();

        times[p] = times[q] = (a[p] - a[q]) / 2 + m;
    }

    if(is_odd(left_even.size()) && is_odd(right_even.size())) {
        int p = left_even.back();
        int q = right_even.front();

        times[p] = times[q] = (a[p] - a[q]) / 2 + m;
    }
}

void solve() {
    
    opp_direction_approach();

    vector<int> left_odd, left_even, right_odd, right_even;
    for(int i = 0;i < n;i++) {
        if(times[i] != -1) continue;

        if(direction[i] == 'L') {
            if(is_odd(a[i])) left_odd.push_back(i);
            else left_even.push_back(i);
        }
        else {
            if(is_odd(a[i])) right_odd.push_back(i);
            else right_even.push_back(i);
        }
    }
    same_direction(left_odd, left_even, right_odd, right_even);

    opp_direction_away(left_odd, left_even, right_odd, right_even);

    for(int i = 0;i < n;i++)
        ans[x[i].second] = times[i];

    for(int i = 0;i < n;i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        read();
        solve();
    }

    return 0;
}