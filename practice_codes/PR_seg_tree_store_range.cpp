#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int INF = static_cast<int>(1e8);

class MergeSortTree {
    private:
        int n;
        vector<vector<int> > t;

        pair<bool, int> binarySearch(const vector<int> &a, int x) {
            int low = 0, high = static_cast<int>(a.size()) - 1;
            int ansIdx = INF;

            while(low <= high) {
                int mid = (low + high) >> 1;
                if(a[mid] >= x) {
                    ansIdx = min(ansIdx, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            if(ansIdx == INF) return {false, 0};
            else return {true, a[ansIdx]};
        }

        inline int left(int i) {return i << 1;}
        inline int right(int i) {return (i << 1) + 1;}

        void merge(int p) {
            const vector<int> &a = t[left(p)];
            const vector<int> &b = t[right(p)];
            const int na = a.size(), nb = b.size();
            int i = 0, j = 0, idx = 0;

            t[p].clear();
            t[p].resize(na + nb);

            while(i < na || j < nb) {
                if(i == na)
                    t[p][idx ++] = b[j ++];
                else if(j == nb)
                    t[p][idx ++] = a[i ++];
                else {
                    if(a[i] <= b[j])
                        t[p][idx ++] = a[i ++];
                    else
                        t[p][idx ++] = b[j ++];
                }
            }
        }

        void buildTree(const vector<int> &a, int p, int L, int R) {
            if(L == R) {
                t[p].clear();
                t[p].push_back(a[L]);
                return;
            }

            int mid = (L + R) >> 1;
            buildTree(a, left(p), L, mid);
            buildTree(a, right(p), mid + 1, R);

            merge(p);
        }

        pair<bool, int> smallestGE(int p, int L, int R, int l, int r, int x) {
            if(l == L && R == r)
                return binarySearch(t[p], x);

            int mid = (L + R) >> 1;
            if(r <= mid)
                return smallestGE(left(p), L, mid, l, r, x);
            else if(l >= mid + 1)
                return smallestGE(right(p), mid + 1, R, l, r, x);
            else {
                pair<bool, int> valLeft
                    = smallestGE(left(p), L, mid, l, mid, x);
                pair<bool, int> valRight
                    = smallestGE(right(p), mid + 1, R, mid + 1, r, x);
                
                if(!valLeft.first)
                    return valRight;
                else if(!valRight.first)
                    return valLeft;
                else
                    return 
                    (valLeft.second < valRight.second ? valLeft : valRight);
            }
        }

    public:
        
        MergeSortTree(const vector<int> &a):
            n(a.size()),
            t(4 * n) {buildTree(a, 1, 0, n - 1);}

        ~MergeSortTree() {}

        inline pair<bool, int> smallestGE(int l, int r, int x) {
            return smallestGE(1, 0, n - 1, l, r, x);
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
    MergeSortTree st(a);

    string query;
    while(cin >> query) {
        if(query == "qry") {
            int l, r, x;
            cin >> l >> r >> x;
            pair<bool, int> retVal = st.smallestGE(l, r, x);
            if(retVal.first)
                cout << retVal.second << "\n";
            else
                cout 
                    << "No value greater than or equal to " 
                    << x 
                    << " in ["
                    << l 
                    << ", " 
                    << r 
                    << "]\n";
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
