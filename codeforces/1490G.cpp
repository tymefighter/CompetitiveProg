#include <iostream>
#include <vector>

using namespace std;

class MergeSortTree {

    private:

    int n;
    vector<vector<long long> > t;

    inline int left(int i) {return i << 1;}
    inline int right(int i) {return (i << 1) + 1;}

    void merge(int idx) {
        const vector<long long> &a = t[left(idx)];
        const vector<long long> &b = t[right(idx)];
        vector<long long> &merge_arr = t[idx];

        merge_arr.resize(a.size() + b.size());
        int ia = 0, ib = 0, i = 0;

        while(ia < a.size() || ib < b.size()) {
            if(ib == b.size()) merge_arr[i ++] = a[ia ++];
            else if(ia == a.size()) merge_arr[i ++] = b[ib ++];
            else {
                if(a[ia] <= b[ib]) merge_arr[i ++] = a[ia ++];
                else merge_arr[i ++] = b[ib ++];
            }
        }
    }

    void build_tree(const vector<long long> &a, int low, int high, int idx) {
        if(low == high) {
            t[idx].push_back(a[low]);
            return;
        }

        int mid = (low + high) >> 1;

        build_tree(a, low, mid, left(idx));
        build_tree(a, mid + 1, high, right(idx));
        merge(idx);
    }

    int get_leftmost_geq_idx(long long x, int low, int high, int idx) {
        if(low == high) {
            if(t[idx][0] >= x) return low;
            else return -1;
        }

        int mid = (low + high) >> 1;
        if(t[left(idx)].back() >= x) 
            return get_leftmost_geq_idx(x, low, mid, left(idx));
        else
            return get_leftmost_geq_idx(x, mid + 1, high, right(idx));
    }

    public:

    MergeSortTree(const vector<long long> &a):
        n(a.size()), t(4 * n) {build_tree(a, 0, n - 1, 1);}

    inline int get_leftmost_geq_idx(long long x) {
        return get_leftmost_geq_idx(x, 0, n - 1, 1);
    }
};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void read_input(vector<long long> &prefix_sum, int &m) {
    int n;
    cin >> n >> m;

    prefix_sum.resize(n);
    cin >> prefix_sum[0];

    for(int i = 1;i < n;i++) {
        int x;
        cin >> x;

        prefix_sum[i] = prefix_sum[i - 1] + x;
    }
}

inline long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

void solve_queries(const vector<long long> &prefix_sum, int &m) {
    int n = prefix_sum.size();
    MergeSortTree merge_sort_tree(prefix_sum);

    long long max_prefix_sum = prefix_sum[0];
    for(int i = 1;i < n;i++) 
        max_prefix_sum = max(max_prefix_sum, prefix_sum[i]);

    long long total_sum = prefix_sum.back();

    while(m --) {
        long long x;
        cin >> x;

        long long num_seconds;
        if(total_sum <= 0 || x <= max_prefix_sum || x < 0)
            num_seconds = merge_sort_tree.get_leftmost_geq_idx(x);
        else {
            long long num_times = ceil_div(x - max_prefix_sum, total_sum);
            x -= num_times * total_sum;
            
            num_seconds = num_times * n + merge_sort_tree.get_leftmost_geq_idx(x);
        }
        
        printf("%lld ", num_seconds);
    }

    printf("\n");
}

int main() {

    enable_fast_io();

    int t;
    cin >> t;

    while(t --) {
        vector<long long> prefix_sum;
        int m;
        read_input(prefix_sum, m);
        solve_queries(prefix_sum, m);
    }

    return 0;
}
