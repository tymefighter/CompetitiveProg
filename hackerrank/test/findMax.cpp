#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int n, a[N], t[4 * N];

inline int left(int i) {return i << 1;}
inline int right(int i){return (i << 1) + 1;}

void build_tree(int p, int L, int R) {

    if(L == R) {
        t[p] = a[L];
        return;
    }

    int mid = (L + R) >> 1;
    build_tree(left(p), L, mid);
    build_tree(right(p), mid + 1, R);

    t[p] = max(t[left(p)], t[right(p)]);
}

// Find the leftmost value greater than x in a[idx .. R]
long long findClosestLargeL(int p, int L, int R, int idx, int x) {
    if(L == R) {
        return static_cast<long long>(a[L] > x ? L : -1);
    }

    int mid = (L + R) >> 1;
    if(idx > mid)
        return findClosestLargeL(right(p), mid + 1, R, idx, x);
    
    if(t[left(p)] > x)
        return findClosestLargeL(left(p), L, mid, idx, x);
    else if(t[right(p)] > x)
        return findClosestLargeL(right(p), mid + 1, R, idx, x);
    else
        return -1;
}

// Find the rightmost value greater than x in a[L .. idx]
long long findClosestLargeR(int p, int L, int R, int idx, int x) {
    if(L == R) {
        return static_cast<long long>(a[L] > x ? L : -1);
    }

    int mid = (L + R) >> 1;
    if(idx <= mid)
        return findClosestLargeR(left(p), L, mid, idx, x);
    
    if(t[right(p)] > x)
        return findClosestLargeR(right(p), mid + 1, R, idx, x);
    else if(t[left(p)] > x)
        return findClosestLargeR(left(p), L, mid, idx, x);
    else
        return -1;
}

int main() {

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    build_tree(1, 0, n - 1);

    long long ans = 0;

    for(int i = 1;i < n - 1;i++) {
        ans = max(ans, (findClosestLargeR(1, 0, n - 1, i - 1, a[i]) + 1) * (findClosestLargeL(1, 0, n - 1, i + 1, a[i]) + 1));
    }

    cout << ans << "\n";

    return 0;
}