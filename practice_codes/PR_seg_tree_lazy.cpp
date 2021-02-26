#include<iostream>
#include<vector>

using namespace std;

class SegmentTreeMax {
    private:
        int n;
        vector<int> t;
        vector<pair<bool, int> > lazy;

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void push(int p, int L, int R) {
            if(!lazy[p].first)
                return;

            t[p] = lazy[p].second;
            if(L < R) {
                lazy[left(p)] = lazy[p];
                lazy[right(p)] = lazy[p];
            }

            lazy[p].first = false;
        }

        void buildTree(const vector<int> &a, int p, int L, int R) {
            if(L == R) {
                t[p] = a[L];
                lazy[p].first = false;
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(a, left(p), L, mid);
            buildTree(a, right(p), mid + 1, R);

            t[p] = max(t[left(p)], t[right(p)]);
            lazy[p].first = false;
        }

        int rangeMaximum(int p, int L, int R, int l, int r) {
            push(p, L, R);

            if(l == L && R == r)
                return t[p];

            int mid = (L + R) >> 1;
            if(r <= mid)
                return rangeMaximum(left(p), L, mid, l, r);
            else if(l >= mid + 1)
                return rangeMaximum(right(p), mid + 1, R, l, r);
            else
                return max(
                    rangeMaximum(left(p), L, mid, l, mid),
                    rangeMaximum(right(p), mid + 1, R, mid + 1, r)
                );
        }

        void updateRange(int p, int L, int R, int l, int r, int x) {
            push(p, L, R);

            if(l == L && R == r) {
                lazy[p] = {true, x};
                push(p, L, R);
                return;
            }

            int mid = (L + R) >> 1;
            if(r <= mid)
                updateRange(left(p), L, mid, l, r, x);
            else if(l >= mid + 1)
                updateRange(right(p), mid + 1, R, l, r, x);
            else {
                updateRange(left(p), L, mid, l, mid, x);
                updateRange(right(p), mid + 1, R, mid + 1, r, x);
            }

            t[p] = max(t[left(p)], t[right(p)]);
        }

    public:

        SegmentTreeMax(const vector<int> &a):
            n(a.size()),
            t(4 * n),
            lazy(4 * n) {buildTree(a, 1, 0, n - 1);}

        ~SegmentTreeMax() {}

        inline int rangeMaximum(int l, int r) {
            return rangeMaximum(1, 0, n - 1, l, r);
        }

        inline void updateRange(int l, int r, int x) {
            updateRange(1, 0, n - 1, l, r, x);
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

    string query;
    while(cin >> query) {
        if(query == "max") {
            int l, r;
            cin >> l >> r;
            cout << st.rangeMaximum(l, r) << "\n";
        }
        else if(query == "update") {
            int l, r, x;
            cin >> l >> r >> x;
            st.updateRange(l, r, x);
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
