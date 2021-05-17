#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

const int N = 300001;
inline int ceil_div(int x, int y) {return (x + y - 1) / y;}

class MinPartition {
    private:

    int n, size;
    int elem_count[N] = {0}, count_arr[N] = {0};

    int get_highest_freq() {
        int low = 0, high = n, ans = 0;

        while(low <= high) {
            int mid = (low + high) >> 1;

            if(count_arr[mid]) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }

    public:

    MinPartition(int n_):
        n(n_), size(0) {}

    void insert(int x) {
        elem_count[x] ++;
        count_arr[elem_count[x]] ++;

        size ++;
    }

    void remove(int x) {
        count_arr[elem_count[x]] --;
        elem_count[x] --;

        size --;
    }

    int get_ans() {
        int highest_freq = get_highest_freq();
        if(highest_freq <= ceil_div(size, 2))
            return 1;

        int other_count = size - highest_freq;
        return highest_freq - other_count;
    }
};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void read_input(
    vector<int> &a, 
    vector<pair<pair<int, int>, int> > &queries
) {
    int n, q;
    cin >> n >> q;

    a.resize(n);
    queries.resize(q);

    for(int i = 0;i < n;i++) cin >> a[i];
    
    for(int i = 0;i < q;i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.first --;
        queries[i].first.second --;
        queries[i].second = i;
    }
}

const long long BLOCK_SIZE = 700;

bool mo_compare(
    pair<pair<int, int>, int> &u, pair<pair<int, int>, int> &v
) {
    int block_u = u.first.first / BLOCK_SIZE;
    int block_v = v.first.first / BLOCK_SIZE;

    if(block_u != block_v) return block_u < block_v;
    
    return u.first.second < v.first.second;
}

void mo(
    vector<int> &a,
    vector<pair<pair<int, int>, int> > &queries,
    vector<int> &ans
) {
    sort(
        queries.begin(), queries.end(), 
        mo_compare
    );

    MinPartition min_partition(a.size());

    int curr_l = queries[0].first.first, curr_r = queries[0].first.second;
    for(int i = curr_l;i <= curr_r;i++)
        min_partition.insert(a[i]);

    ans.resize(queries.size());
    ans[queries[0].second] = min_partition.get_ans();
    
    for(int q = 1;q < queries.size();q++) {
        int l = queries[q].first.first, r = queries[q].first.second;

        while(curr_l > l) min_partition.insert(a[-- curr_l]);

        while(curr_r < r) min_partition.insert(a[++ curr_r]);

        while(curr_l < l) min_partition.remove(a[curr_l ++]);

        while(curr_r > r) min_partition.remove(a[curr_r --]);

        ans[queries[q].second] = min_partition.get_ans();
    }
}

int main() {

    enable_fast_io();

    vector<int> a;
    vector<pair<pair<int, int>, int> > queries;
    vector<int> ans;

    read_input(a, queries);
    mo(a, queries, ans);

    for(int x : ans) cout << x << "\n";

    return 0;
}