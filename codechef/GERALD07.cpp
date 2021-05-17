#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class UnionFind {
    private:

    int n, num_comp;
    vector<int> rank, p;
    stack<int> s; // (node which was independent)

    public:

    UnionFind(int n_):
        n(n_), num_comp(n), rank(n, 0), p(n) {
            for(int i = 0;i < n;i++) p[i] = i;
        }

    int find_set(int u) {
        while(u != p[u]) u = p[u];

        return u; 
    }

    void union_set(int u, int v) {
        u = find_set(u), v = find_set(v);

        if(u == v) {
            s.push(u);
            return;
        }

        if(rank[u] > rank[v]) {
            p[v] = u;
            s.push(v);
        }
        else if(rank[u] < rank[v]) {
            p[u] = v;
            s.push(u);
        }
        else {
            p[v] = u;
            s.push(v);
            rank[u] ++;
        }

        num_comp--;
    }

    void undo() {

        if(p[s.top()] != s.top()) num_comp ++;

        p[s.top()] = s.top();
        s.pop();
    }

    inline int get_num_comp() {return num_comp;}
};

struct Query {
    int l, r, idx;

    Query(int l_, int r_, int idx_):
        l(l_), r(r_), idx(idx_) {}

    Query() {}
};

inline void enable_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, m, q;
vector<pair<int, int> > edge;

void read() {
    cin >> n >> m >> q;

    edge.clear();
    edge.resize(m);

    for(int i = 0;i < m;i++) {
        cin >> edge[i].first >> edge[i].second;
        edge[i].first --, edge[i].second --;
    }
}

bool block_compare(const Query &a, const Query &b) {
    return a.r < b.r;
}

void solve() {
    const int block_size = ceil(sqrt(m));
    int num_block = (m + block_size - 1) / block_size;

    vector<vector<Query> > block(num_block);

    for(int i = 0;i < q;i++) {
        int l, r;
        cin >> l >> r;
        l --, r --;

        block[l / block_size].push_back(Query(l, r, i));
    }

    vector<int> ans(q);
    for(int block_idx = 0;block_idx < num_block;block_idx ++) {

        vector<Query> &curr_block = block[block_idx];
        if(curr_block.empty()) continue;

        sort(curr_block.begin(), curr_block.end(), block_compare);

        int block_left_idx = block_idx * block_size;
        int block_right_idx = min((block_idx + 1) * block_size - 1, m - 1);

        UnionFind ufds(n);
        int prev_r = block_left_idx - 1;

        for(Query &query: curr_block) {
            int l = query.l, r = query.r;

            for(int i = max(prev_r + 1, block_right_idx + 1);i <= r;i++)
                ufds.union_set(edge[i].first, edge[i].second);

            for(int i = l;i <= min(block_right_idx, r);i++)
                ufds.union_set(edge[i].first, edge[i].second);
            
            ans[query.idx] = ufds.get_num_comp();

            for(int i = l;i <= min(block_right_idx, r);i++)
                ufds.undo();

            if(r <= block_right_idx) prev_r = block_left_idx - 1;
            else prev_r = r;
        }
    }

    for(int i = 0;i < q;i++) cout << ans[i] << "\n";
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