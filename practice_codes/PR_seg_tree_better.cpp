#include<iostream>
#include<vector>

using namespace std;

class SegmentTreeMax {
    private:
        int n;
        vector<int> t;

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void buildTree(const vector<int> &a, int p, int L, int R) {
            if(L == R) {
                t[p] = a[L];
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(a, left(p), L, mid);
            buildTree(a, right(p), mid + 1, R);

            t[p] = max(t[left(p)], t[right(p)]);
        }

        int rangeMax(int p, int L, int R, int l, int r) {
            if(l == L && R == r)
                return t[p];

            int mid = (L + R) >> 1;
            if(r <= mid)
                return rangeMax(left(p), L, mid, l, r);
            else if(l >= mid + 1)
                return rangeMax(right(p), mid + 1, R, l, r);
            else
                return max(
                    rangeMax(left(p), L, mid, l, mid),
                    rangeMax(right(p), mid + 1, R, mid + 1, r)
                );
        }

        void pointUpdate(int p, int L, int R, int idx, int x) {
            if(L == R) {
                t[p] = x;
                return;
            }

            int mid = (L + R) >> 1;
            if(idx <= mid)
                pointUpdate(left(p), L, mid, idx, x);
            else
                pointUpdate(right(p), mid + 1, R, idx, x);

            t[p] = max(t[left(p)], t[right(p)]);
        }

    public:
        SegmentTreeMax(const vector<int> &a):
            n(a.size()),
            t(4 * n) {buildTree(a, 1, 0, n - 1);}
        
        ~SegmentTreeMax() {}

        inline int rangeMax(int l, int r) {
            return rangeMax(1, 0, n - 1, l, r);
        }

        inline void pointUpdate(int idx, int x) {
            pointUpdate(1, 0, n - 1, idx, x);
        }
};

class SegmentTreeZero {
    private:
        int n;
        vector<int> t;

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void buildTree(const vector<int> &a, int p, int L, int R) {
            if(L == R) {
                t[p] = (a[L] == 0 ? 1 : 0);
                return;
            }
        
            int mid = (L + R) >> 1;
            buildTree(a, left(p), L, mid);
            buildTree(a, right(p), mid + 1, R);

            t[p] = t[left(p)] + t[right(p)];
        }

        int numZero(int p, int L, int R, int l, int r) {
            if(l == L & R == r)
                return t[p];

            int mid = (L + R) >> 1;
            if(r <= mid)
                return numZero(left(p), L, mid, l, r);
            else if(l >= mid + 1)
                return numZero(right(p), mid + 1, R, l, r);
            else
                return numZero(left(p), L, mid, l, mid)
                    + numZero(right(p), mid + 1, R, mid + 1, r);
        }

        int indexOfkthZero(int p, int L, int R, int k) {
            if(L == R)
                return L;

            int mid = (L + R) >> 1;

            if(t[left(p)] >= k + 1)
                return indexOfkthZero(left(p), L, mid, k);
            else
                return indexOfkthZero(right(p), mid + 1, R, k - t[left(p)]);
        }

        void pointUpdate(int p, int L, int R, int idx, int x) {
            if(L == R) {
                t[p] = (x == 0 ? 1 : 0);
                return;
            }

            int mid = (L + R) >> 1;
            if(idx <= mid)
                pointUpdate(left(p), L, mid, idx, x);
            else
                pointUpdate(right(p), mid + 1, R, idx, x);

            t[p] = t[left(p)] + t[right(p)];
        }

    public:

        SegmentTreeZero(const vector<int> &a):
            n(a.size()),
            t(4 * n) {buildTree(a, 1, 0, n - 1);}

        ~SegmentTreeZero() {}

        inline int numZero(int l, int r) {
            return numZero(1, 0, n - 1, l, r);
        }

        inline int indexOfkthZero(int k) {
            if(t[1] <= k) // total number of zeros is less than k
                return -1;

            return indexOfkthZero(1, 0, n - 1, k);
        }

        inline void pointUpdate(int idx, int x) {
            pointUpdate(1, 0, n - 1, idx, x);
        }
};

void readInput(vector<int> &a) {
    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

void processOp(const vector<int> &a) {
    SegmentTreeMax st(a);
    SegmentTreeZero stZero(a);

    string query;
    while(cin >> query) {
        if(query == "max") {
            int l, r;
            cin >> l >> r;
            cout << st.rangeMax(l, r) << "\n";
        }
        else if(query == "update") {
            int idx, x;
            cin >> idx >> x;
            st.pointUpdate(idx, x);
            stZero.pointUpdate(idx, x);
        }
        else if(query == "zero") {
            int l, r;
            cin >> l >> r;
            cout << stZero.numZero(l, r) << "\n";
        }
        else if(query == "kth") {
            int k;
            cin >> k;
            cout << stZero.indexOfkthZero(k) << "\n";
        }
        else if(query == "done") break;
    }
}

int main() {

    vector<int> a;

    readInput(a);
    processOp(a);

    return 0;
}