#include<iostream>

using namespace std;

const int N = 105;
int n, x, m;
pair<int, int> p[N];
bool can_reach[N];

void readInput() {
    cin >> n >> x >> m;
    for(int i = 0;i < m;i++) {
        cin >> p[i].first >> p[i].second;
        can_reach[i] = false;
    }
}

bool intersect(int i, int j) {
    return (p[i].first <= p[j].first && p[i].second >= p[j].first)
        || (p[j].first <= p[i].first && p[j].second >= p[i].first);
}

void solve() {
    int l = -1, r = -1;

    for(int i = 0;i < m;i++) {
        if(p[i].first <= x && x <= p[i].second)
            can_reach[i] = true;
        for(int j = 0;j < i;j++) {
            if(can_reach[j] && intersect(i, j))
                can_reach[i] = true;
        }

        if(can_reach[i]) {
            if(l == -1) {
                l = p[i].first;
                r = p[i].second;
            }
            else {
                l = min(l, p[i].first);
                r = max(r, p[i].second);
            }
        }
    }

    cout << r - l + 1 << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while(t --) {
        readInput();
        solve();
    }
    return 0;
}