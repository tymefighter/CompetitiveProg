#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200000;
vector<vector<int> > a;
int n, val[N], p[N];

vector<vector<int> > depth_nodes;

void read_input() {
    scanf("%d ", &n);

    a.clear();
    a.resize(n);
    depth_nodes.clear();
    depth_nodes.resize(n);

    for(int i = 1;i < n;i++) {
        int u;
        scanf("%d ", &u);
        u --;
        a[u].push_back(i);
        a[i].push_back(u);
    }

    val[0] = 0;
    for(int i = 1;i < n;i++) scanf("%d ", &val[i]);
}

int dfs_compute_depth(int u, int parent, int depth) {
    p[u] = parent;
    depth_nodes[depth].push_back(u);

    int max_depth = 0;
    for(int v : a[u]) {
        if(v == parent) continue;
        max_depth = max(
            max_depth, 
            dfs_compute_depth(v, u, depth + 1) + 1
        );
    }

    return max_depth;
}

long long dp[N];

void solve() {
    int max_depth = dfs_compute_depth(0, -1, 0);
    dp[0] = 0;

    for(int depth = 1;depth <= max_depth;depth ++) {
        int m = depth_nodes[depth].size();
        vector<pair<int, pair<long long, long long> > > val_arr(m);

        for(int i = 0;i < m;i++) {
            int u = depth_nodes[depth][i];
            val_arr[i] = {val[u], {dp[p[u]] - val[u], dp[p[u]] + val[u]}};
        }
        
        sort(val_arr.begin(), val_arr.end());
        vector<long long> less_max(m), more_max(m);
        
        less_max[0] = val_arr[0].second.first;
        for(int i = 1;i < m;i++)
            less_max[i] = max(less_max[i - 1], val_arr[i].second.first);

        more_max[m - 1] = val_arr[m - 1].second.second;
        for(int i = m - 2;i >= 0;i--)
            more_max[i] = max(more_max[i + 1], val_arr[i].second.second);

        for(int u : depth_nodes[depth]) {
            if(val[u] >= val_arr[m - 1].first) {
                dp[u] = val[u] + less_max[m - 1];
            }
            else if(val[u] < val_arr[0].first) {
                dp[u] = more_max[0] - val[u];
            }
            else {
                int low = 0, high = m - 1, max_idx = 0;
                while(low <= high) {
                    int mid = (low + high) >> 1;

                    if(val[u] >= val_arr[mid].first) {
                        max_idx = max(max_idx, mid);
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }

                dp[u] = max(val[u] + less_max[max_idx], more_max[max_idx + 1] - val[u]);
            }

            dp[u] = max(
                dp[u], 
                dp[p[u]] + max(
                    abs(val[u] - val_arr.front().first), 
                    abs(val[u] - val_arr.back().first)
                )
            );
        }
    }

    long long ans = 0;
    for(int u : depth_nodes[max_depth]) ans = max(ans, dp[u]);
    printf("%lld\n", ans);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        read_input();
        solve();
    }

    return 0;
}