#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class SegmentTree {
    private:
        int n;
        vector<long long> t;

        inline int left(int i) const {return i << 1;}
        inline int right(int i) const {return (i << 1) + 1;}

        void buildTree(
            const vector<pair<int, int> > &allowed,
            int p,
            int L,
            int R
        ) {
            if(L == R) {
                t[p] = allowed[L].second;
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(allowed, left(p), L, mid);
            buildTree(allowed, right(p), mid + 1, R);

            t[p] = t[left(p)] + t[right(p)];
        }

        long long rsq(int p, int L, int R, int l, int r) const {
            if(l == L && R == r)
                return t[p];
            
            int mid = (L + R) >> 1;
            if(r <= mid)
                return rsq(left(p), L, mid, l, r);
            else if(l > mid)
                return rsq(right(p), mid + 1, R, l, r);
            else
                return rsq(left(p), L, mid, l, mid)
                    + rsq(right(p), mid + 1, R, mid + 1, r);
        }

    public:

        SegmentTree():
            n(0),
            t(0) {}

        ~SegmentTree() {}

        void reset(const vector<pair<int, int> > &allowed) {
            t.clear();
            n = allowed.size();
            t.resize(4 * n);
            buildTree(allowed, 1, 0, n - 1);
        }

        inline long long rsq(int l, int r) const {return rsq(1, 0, n - 1, l, r);}

        SegmentTree& operator= (const SegmentTree &sTree) {
            n = sTree.n;
            t = sTree.t;
            return *this;
        }
};

class RangeInfo {
    private:
        int n;
        vector<pair<int, int> > allowed; // (height, val) sorted inc by height
        vector<int> allowedInd2ind;
        map<int, int> ind2allowedInd;
        SegmentTree ft;
    public:

        RangeInfo():
            n(0) {}

        RangeInfo(int ht, int val, int idx):
            n(1),
            allowed(1, {ht, val}),
            allowedInd2ind(1, idx),
            ind2allowedInd(),
            ft() {
                ft.reset(allowed);
                ind2allowedInd[idx] = 0;
            }

        RangeInfo(const RangeInfo &left, const RangeInfo &right):
            n(left.n),
            allowed(left.allowed),
            allowedInd2ind(left.allowedInd2ind),
            ind2allowedInd(left.ind2allowedInd),
            ft() {
                
                int prevHt = allowed[n - 1].first;
                for(int i = 0;i < right.n;i++) {
                    const pair<int, int> &x = right.allowed[i];
                    if(x.first > prevHt) {
                        prevHt = x.first;
                        allowed.push_back(x);
                        allowedInd2ind.push_back(right.allowedInd2ind[i]);
                        n ++;
                        ind2allowedInd[allowedInd2ind[n - 1]] = n - 1;
                    }
                }

                ft.reset(allowed);
            }

        RangeInfo& operator= (const RangeInfo &rangeInfo) {
            n = rangeInfo.n;
            allowed = rangeInfo.allowed;
            allowedInd2ind = rangeInfo.allowedInd2ind;
            ind2allowedInd = rangeInfo.ind2allowedInd;
            ft = rangeInfo.ft;
            return *this;
        }

        ~RangeInfo() {}

        pair<int, long long> searchLeftMostLarger(int x) const {
            int low = 0, high = n - 1, ansIdx = n;

            while(low <= high) {
                int mid = (low + high) >> 1;
                if(allowed[mid].first > x) {
                    ansIdx = min(ansIdx, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            if(ansIdx == n)
                return {x, 0ll};
            
            return {
                allowed[n - 1].first,
                ft.rsq(ansIdx, n - 1)
            };
        }
};

class SegTree {
    private:
        int n;
        int *h, *a;
        vector<RangeInfo> t;

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void buildTree(
            int p,
            int L,
            int R
        ) {
            if(L == R) {
                t[p] = RangeInfo(h[L], a[L], L);
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(left(p), L, mid);
            buildTree(right(p), mid + 1, R);

            t[p] = RangeInfo(t[left(p)], t[right(p)]);
        }

        void getAllRange(
            vector<int> &idx,
            int p,
            int L,
            int R,
            int l,
            int r
        ) {
            if(l == L && R == r) {
                idx.push_back(p);
                return;
            }

            int mid = (L + R) >> 1;

            if(r <= mid)
                getAllRange(idx, left(p), L, mid, l, r);
            else if(l >= mid + 1)
                getAllRange(idx, right(p), mid + 1, R, l, r);
            else {
                getAllRange(idx, left(p), L, mid, l, mid);
                getAllRange(idx, right(p), mid + 1, R, mid + 1, r);
            }
        }

    public:

        SegTree(int n_, int *h_, int *a_):
            n(n_),
            h(h_),
            a(a_),
            t(4 * n) {
                buildTree(1, 0, n - 1);
            }
        
        ~SegTree() {}

        long long rangeQuery(int l, int r) {

            if(l == r)
                return a[l];

            vector<int> idx;
            getAllRange(idx, 1, 0, n - 1, l, r - 1);

            int maxHt = -1;
            long long ans = a[r];

            for(int i : idx) {
                const RangeInfo &rangeInfo = t[i];
                pair<int, long long> val = rangeInfo.searchLeftMostLarger(maxHt);
                ans += val.second;
                maxHt = val.first;
                if(maxHt >= h[r])
                    return -1ll;
            }

            return ans;
        }
};

void readInput(int &n, int &q, int *h, int *a, int *hr, int *ar) {
    for(int i = 0;i < n;i++) {
        scanf("%d ", &h[i]);
        hr[n - i - 1] = h[i];
    }

    for(int i = 0;i < n;i++) {
        scanf("%d ", &a[i]); 
        ar[n - i - 1] = a[i];
    }
}

void handleQueries(
    int n,
    int q,
    int *h,
    int *a,
    int *hr,
    int *ar
) {
    SegTree t1(n, h, a);
    SegTree t2(n, hr, ar);
    
    while(q --) {
        int qType;
        scanf("%d ", &qType);

        assert(qType == 2);

        if(qType == 1)
            continue;
        else {
            int start, end;
            scanf("%d %d ", &start, &end);
            start --, end --;

            if(start >= end)
                printf("%lld\n", t1.rangeQuery(end, start));
            else
                printf("%lld\n", t2.rangeQuery(n - end - 1, n - start - 1));
        }
    }
}

const int N = 200005;
int h[N], a[N], hr[N], ar[N];

int main() {

    int n, q;
    scanf("%d %d ", &n, &q);
    readInput(n, q, h, a, hr, ar);
    handleQueries(n, q, h, a, hr, ar);

    return 0;
}