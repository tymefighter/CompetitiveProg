#include<iostream>
#include<stack>

using namespace std;

const int N = 1005;
int n, q, d[N];

void readInput() {
    cin >> n >> q;
    for(int i = 0;i < n - 1;i++)
        cin >> d[i];
}

void solveQuery(int s, int k) {
    stack<pair<int, int> > left, right;
    for(int i = 0;i < s;i++)
        left.push({d[i], i});
    for(int i = n - 2;i >= s;i--)
        right.push({d[i], i + 1});

    int u = s;
    while(k) {
        if(left.empty()) {
            u = right.top().second;
            right.pop();
        }
        else if(right.empty()) {
            u = left.top().second;
            left.pop();
        }
        else {
            if(left.top() < right.top()) {
                u = left.top().second;
                left.pop();
            }
            else {
                u = right.top().second;
                right.pop();
            }
        }
        k --;
    }

    cout << u + 1 << " ";
}

void solve() {
    while(q --) {
        int s, k;
        cin >> s >> k;
        s --;
        k --;
        solveQuery(s, k);
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}