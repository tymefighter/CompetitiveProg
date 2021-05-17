#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100;
int n, m, b[N][N], assign[N][N];
vector<pair<int, pair<int, int> > > sort_val;

void read() {
    cin >> n >> m;
    sort_val.clear();
    sort_val.resize(n * m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> b[i][j];
            assign[i][j] = -1;
            sort_val[i * m + j] = {b[i][j], {i, j}};
        }
    }

    sort(sort_val.begin(), sort_val.end());
}

void solve() {
    for(int i = 0;i < m;i++)
        assign[sort_val[i].second.first][i] = sort_val[i].second.second;

    for(int i = 0;i < n;i++) {
        unordered_set<int> st;

        for(int j = 0;j < m;j++)
            if(assign[i][j] != -1) st.insert(assign[i][j]);

        stack<int> unused;
        for(int j = 0;j < m;j++) {
            if(st.find(j) == st.end()) unused.push(j);
        }

        for(int j = 0;j < m;j++) {
            if(assign[i][j] == -1) {
                assign[i][j] = unused.top();
                unused.pop();
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cout << b[i][assign[i][j]] << " ";
        cout << "\n";
    }
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