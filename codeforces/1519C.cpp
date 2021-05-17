#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 200000;
int n, u[N];
vector<long long> univ_sum;
vector<vector<long long> > univ, univ_pre;
vector<pair<int, int> > univ_num_std_sort;

void read_compute() {
    cin >> n;
    
    univ_sum.clear();
    univ_sum.assign(n, 0);

    univ.clear();
    univ.resize(n);

    univ_pre.clear();
    univ_pre.resize(n);

    univ_num_std_sort.clear();
    univ_num_std_sort.resize(n);

    for(int i = 0;i < n;i++) cin >> u[i];
    for(int i = 0;i < n;i++) {
        int s, j = u[i] - 1;
        cin >> s;

        univ_sum[j] += s;
        univ[j].push_back(s);
    }

    for(int j = 0;j < n;j++) {
        sort(univ[j].begin(), univ[j].end());
        
        univ_pre[j].resize(univ[j].size());

        for(int i = 0;i < univ[j].size();i++)
            univ_pre[j][i] = univ[j][i] + (i > 0 ? univ_pre[j][i - 1] : 0);

        univ_num_std_sort[j] = {univ[j].size(), j};
    }

    sort(univ_num_std_sort.begin(), univ_num_std_sort.end());
    reverse(univ_num_std_sort.begin(), univ_num_std_sort.end());
}

void solve() {
    for(int k = 1;k <= n;k++) {
        while(!univ_num_std_sort.empty()
            && univ_num_std_sort.back().first < k) 
            univ_num_std_sort.pop_back();

        long long sum_value = 0;
        for(pair<int, int> count_idx : univ_num_std_sort) {
            int idx = count_idx.second;
            int r = count_idx.first % k - 1;
            
            sum_value += univ_sum[idx] - (r >= 0 ? univ_pre[idx][r] : 0);
        }

        cout << sum_value << " ";
    }

    cout << "\n";
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        read_compute();
        solve();
    }

    return 0;
}