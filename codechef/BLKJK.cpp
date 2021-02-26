#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = static_cast<int>(1e7);

class SparseTable {

    private:

    int n, m;
    vector<vector<int> > st;

    void buildTable(const vector<int> &a) {
        for(int i = 0;i < n;i++)
            st[0][i] = a[i];

        for(int k = 1;k < m;k++) {
            for(int i = 0;i + (1 << k) <= n;i++)
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    public:

    SparseTable(const vector<int> &a):
        n(a.size()), m(log2(n) + 1),
        st(m, vector<int>(n)) {buildTable(a);}

    ~SparseTable() {}

    int minValue(int l, int r) {
        int maxPow = log2(r - l + 1);

        return min(st[maxPow][l], st[maxPow][r - (1 << maxPow) + 1]);
    }
};

inline void enableFastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void readInput(vector<int> &a, int &x, int &y) {
    int n;
    
    cin >> n >> x >> y;
    a.resize(n);

    for(int i = 0;i < n;i++)
        cin >> a[i];
}

void computeMinNotPick(
    const vector<int> &a,
    const int MAX_VAL,
    vector<vector<int> > &minNotPick
) {
    int n = a.size();
    minNotPick.assign(n, vector<int>(MAX_VAL + 1));

    minNotPick[0][0] = 1;
    for(int val = 1;val <= MAX_VAL;val++)
        minNotPick[0][val] = (val == a[0] ? 0 : INF);

    for(int i = 1;i < n;i++) {
        for(int val = 0;val <= MAX_VAL;val++) {
            minNotPick[i][val] = minNotPick[i - 1][val] + 1;

            if(val >= a[i])
                minNotPick[i][val] = 
                    min(minNotPick[i][val], minNotPick[i - 1][val - a[i]]);
        }
    }
}

void computeMinEndPick(
    const vector<int> &a,
    const int MAX_VAL,
    vector<vector<int> > &minEndPick
) {
    int n = a.size();
    minEndPick.assign(n, vector<int>(MAX_VAL + 1));

    minEndPick[n - 1][0] = 0;
    for(int val = 1;val <= MAX_VAL;val++)
        minEndPick[n - 1][val] = (val == a[n - 1] ? 1 : INF);

    for(int i = n - 2;i >= 0;i--) {
        for(int val = 0;val <= MAX_VAL;val++) {
            minEndPick[i][val] = minEndPick[i + 1][val];

            if(val >= a[i])
                minEndPick[i][val] =
                    min(minEndPick[i][val], minEndPick[i + 1][val - a[i]] + 1);
        }
    }
}

void computeDP(
    const vector<int> &a,
    const int MAX_VAL,
    vector<vector<int> > &minNotPick,
    vector<vector<int> > &minEndPick
) {
    computeMinNotPick(a, MAX_VAL, minNotPick);
    computeMinEndPick(a, MAX_VAL, minEndPick);
}

void buildSparseTables(
    const vector<vector<int> > &minEndPick,
    vector<SparseTable *> &minEndPickSparseTables
) {
    int n = minEndPick.size();
    minEndPickSparseTables.assign(n, nullptr);
    for(int i = 0;i < n;i++)
        minEndPickSparseTables[i] = new SparseTable(minEndPick[i]);
}

void deleteSparseTables(
    vector<SparseTable *> &minEndPickSparseTables
) {
    for(SparseTable *sparseTable : minEndPickSparseTables)
        delete sparseTable;
}

int computeMinSwaps(const vector<int> &a, int x, int y) {
    int n = a.size(), totalSum = 0;

    for(int u : a)
        totalSum += u;
    
    if(x <= totalSum && totalSum <= y) return 0;

    vector<vector<int> > minNotPick, minEndPick;
    vector<SparseTable *> minEndPickSparseTables;

    computeDP(a, y, minNotPick, minEndPick);
    buildSparseTables(minEndPick, minEndPickSparseTables);

    int result = INF;
    for(int i = 0;i < n - 1;i++) {
        for(int u = 0;u <= y;u++) {
            result = min(
                result, 
                max(
                    minNotPick[i][u], 
                    minEndPickSparseTables[i + 1]->minValue(max(x - u, 0), y - u)
                )
            );
        }
    }
    
    deleteSparseTables(minEndPickSparseTables);

    return result == INF ? -1 : result;
}

int main() {
    enableFastIO();

    int t;
    cin >> t;

    while(t --) {
        vector<int> a;
        int x, y;

        readInput(a, x, y);
        cout << computeMinSwaps(a, x, y) << "\n";
    }

    return 0;
}

