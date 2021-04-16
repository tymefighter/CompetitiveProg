#include <iostream>
#include <vector>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1000;
int n, m;
char a[N][N];

int parent_a[N], parent_b[N];
int child_a[N], child_b[N];

void read_input() {
    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cin >> a[i][j];

        parent_a[i] = parent_b[i] = child_a[i] = child_b[i] = -1;
    }
}

void print_repeat(
    const vector<int> &rep_arr
) {
    cout << "YES\n";

    for(int i = 0;i < m + 1;i++)
        cout << rep_arr[i % rep_arr.size()] + 1 << " ";

    cout << "\n";
}

void solve() {
    if(m & 1) {
        print_repeat({0, 1});
        return;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            if(a[i][j] == a[j][i]) {
                print_repeat({i, j});
                return;
            }
        }
    }
    
    if(n == 2) {
        cout << "NO\n";
        return;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(i == j) continue;

            if(a[i][j] == 'a') {
                child_a[i] = j;
                parent_a[j] = i;
            }
            else {
                child_b[i] = j;
                parent_b[j] = i;
            }
        }
    }

    int x, y, z;
    for(int i = 0;i < n;i++) {
        if(parent_a[i] != -1 && child_a[i] != -1) {
            x = parent_a[i], y = i, z = child_a[i];
            break;
        }
        else if(parent_b[i] != -1 && child_b[i] != -1) {
            x = parent_b[i], y = i, z = child_b[i];
            break;
        }
    }

    if((m >> 1) & 1) print_repeat({x, y, z, y});
    else print_repeat({y, z, y, x});
}

int main() {
    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}