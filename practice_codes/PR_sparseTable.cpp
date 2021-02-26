#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class SparseTable {
    private:
        const int n, maxPow;
        vector<vector<int> > st;
    public:
        SparseTable(const vector<int> &a):
            n(a.size()),
            maxPow(log2(n)),
            st(maxPow + 1, vector<int>(n)) {
                for(int i = 0;i < n;i++)
                    st[0][i] = a[i];

                for(int j = 1;j <= maxPow;j++) {
                    for(int i = 0;i + (1 << j) - 1 < n;i++)
                        st[j][i] 
                            = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
                }
            }

        ~SparseTable() {}

        int sum(int l, int r) {
            int maxPow = static_cast<int>(log2(r - l + 1));
            return 
                st[maxPow][l]
                + (l + (1 << maxPow) - 1 == r ? 0 : sum(l + (1 << maxPow), r));
        }
};

class SparseTableMin {
    private:
        const int n, maxPow;
        vector<vector<int> > st;
    public:
        SparseTableMin(const vector<int> &a):
            n(a.size()),
            maxPow(log2(n)),
            st(maxPow + 1, vector<int>(n)) {
                
                for(int i = 0;i < n;i++)
                    st[0][i] = a[i];

                for(int j = 1;j <= maxPow;j++) {
                    for(int i = 0;i + (1 << j) - 1 < n;i++)
                        st[j][i] = 
                            min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                }
            }

        ~SparseTableMin() {}

        int rangeMinimum(int l, int r) {
            int maxPow = log2(r - l + 1);
            return min(st[maxPow][l], st[maxPow][r - (1 << maxPow) + 1]);
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

void answerQueries(const vector<int> &a) {
    SparseTable st(a);
    SparseTableMin stMin(a);

    string query;
    while(cin >> query) {
        if(query == "sum") {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
        else if(query == "min") {
            int l, r;
            cin >> l >> r;
            cout << stMin.rangeMinimum(l, r) << "\n";
        }
        else if(query == "done") break;
    }
}

int main() {
    vector<int> a;

    readInput(a);
    answerQueries(a);

    return 0;
}