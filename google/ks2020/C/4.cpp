#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int n, q;
vector<long long> a, st1, st2;

inline int left(int i) {return i << 1;}
inline int right(int i) {return (i << 1) + 1;}

void build_tree(vector<long long> &t, int p, int L, int R, bool is_tree_one) {
    if(L == R) {
        if(is_tree_one)
            t[p] = (L % 2 == 0 ? 1 : -1) * a[L] * (L + 1);
        else
            t[p] = (L % 2 == 0 ? 1 : -1) * a[L];
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(t, left(p), L, mid, is_tree_one);
    build_tree(t, right(p), mid + 1, R, is_tree_one);

    t[p] = t[left(p)] + t[right(p)];
}

long long rsq(const vector<long long> &t, int p, int L, int R, int l, int r) {
    if(l == L && R == r)
        return t[p];

    int mid = (L + R) >> 1;
    if(r <= mid)
        return rsq(t, left(p), L, mid, l, r);
    else if(l >= mid + 1)
        return rsq(t, right(p), mid + 1, R, l, r);
    else
        return rsq(t, left(p), L, mid, l, mid)
            + rsq(t, right(p), mid + 1, R, mid + 1, r);
}

void update(vector<long long> &t, int p, int L, int R, int idx, long long val, bool is_tree_one) {
    if(L == R) {
        if(is_tree_one)
            t[p] = (L % 2 == 0 ? 1 : -1) * val * (L + 1);
        else
            t[p] = (L % 2 == 0 ? 1 : -1) * val;

        return;
    }

    int mid = (L + R) >> 1;
    if(idx <= mid)
        update(t, left(p), L, mid, idx, val, is_tree_one);
    else
        update(t, right(p), mid + 1, R, idx, val, is_tree_one);

    t[p] = t[left(p)] + t[right(p)];
}

void readInput() {
    cin >> n >> q;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];

    st1.clear();
    st1.resize(4 * n);
    st2.clear();
    st2.resize(4 * n);

    build_tree(st1, 1, 0, n - 1, true);
    build_tree(st2, 1, 0, n - 1, false);
}

long long solve() {
    long long val = 0;
    char qry;
    while(q --) {
        cin >> qry;

        assert(qry == 'U' || qry == 'Q');

        if(qry == 'U') {
            int idx;
            long long val;
            cin >> idx >> val;
            idx --;
            update(st1, 1, 0, n - 1, idx, val, true);
            update(st2, 1, 0, n - 1, idx, val, false);
        }
        else if(qry == 'Q') {
            int l, r;
            cin >> l >> r;
            l --, r --;
            val += (rsq(st1, 1, 0, n - 1, l, r) - rsq(st2, 1, 0, n - 1, l, r) * l) * (l % 2 == 0 ? 1 : -1);
        }
    }

    return val;
}

int main() {
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}