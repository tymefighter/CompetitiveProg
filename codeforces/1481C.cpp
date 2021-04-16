#include <iostream>
#include <vector>
#include <stack>

using namespace std;

inline void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 100000;
int n, m;
int a[N], b[N], c[N], ans[N];
vector<stack<int> > occ;

void read_input() {
    cin >> n >> m;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    occ.clear();
    occ.resize(n + 1);
    for(int i = 0;i < m;i++) {
        cin >> c[i];
        ans[i] = -1;

        if(i < m - 1) occ[c[i]].push(i);
    }
}

bool solve() {
    int last_idx = -1;
    for(int i = 0;i < n;i++) {
        if(b[i] == c[m - 1]) {
            if(last_idx == -1 || b[i] != a[i]) 
                last_idx = i;
        }
    }

    if(last_idx == -1) return false;

    ans[m - 1] = last_idx;

    for(int i = 0;i < n;i++) {
        if(i == last_idx || a[i] == b[i]) continue;

        if(occ[b[i]].empty()) return false;

        int idx = occ[b[i]].top();
        occ[b[i]].pop();

        ans[idx] = i;
    }

    for(int i = 0;i < m;i++)
        if(ans[i] == -1) ans[i] = last_idx;

    return true;
}

int main() {

    fast_io();

    int t;
    cin >> t;

    while(t --) {
        read_input();
        if(solve()) {
            cout << "yes\n";
            for(int i = 0;i < m;i++)
                cout << ans[i] + 1 << " ";
            cout << "\n";
        }
        else cout << "no\n";
    }


    return 0;
}