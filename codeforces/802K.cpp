#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100000;
int n, k;
vector<vector<pair<int, int> > > a;
long long dp[N][2]; 
// (u, 1) -> come back to u, (u, 0) -> don't need to come back

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void read_input() {
    cin >> n >> k;
    a.resize(n);
    
    for(int i = 0;i < n - 1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
}

void compute_dp(int u, int p) {
    vector<pair<long long, int> > come_back_val, come_back_val_sort;
    vector<long long> no_come_back_val;

    int child_num = 0;
    for(pair<int, int> v : a[u]) {
        if(v.first == p) continue;

        compute_dp(v.first, u);
        come_back_val.push_back({dp[v.first][true] + v.second, child_num});
        no_come_back_val.push_back(dp[v.first][false] + v.second);
        child_num ++;
    }

    come_back_val_sort = come_back_val;
    sort(come_back_val_sort.begin(), come_back_val_sort.end(), 
        greater<pair<long long, int> > ());

    int num_child = k - 1;

    long long max_sum = 0;
    set<int> index_set;
    for(int i = 0;i < min(num_child, (int)come_back_val_sort.size());i++) {
        max_sum += come_back_val_sort[i].first;
        index_set.insert(come_back_val_sort[i].second);
    }

    // Come Back
    dp[u][1] = max_sum;

    // No Come Back
    dp[u][0] = 0;
    for(int i = 0;i < no_come_back_val.size();i++) {
        long long value = no_come_back_val[i];

        if(index_set.find(i) == index_set.end())
            value += max_sum;
        else {
            value += max_sum - come_back_val[i].first
                + (num_child < come_back_val_sort.size() ?
                    come_back_val_sort[num_child].first
                    : 0);
        }

        dp[u][0] = max(dp[u][0], value);
    }
}

int main() {

    enable_fast_io();

    read_input();
    compute_dp(0, -1);
    cout << max(dp[0][1], dp[0][0]) << "\n";

    return 0;
}