#include<iostream>
#include<vector>

using namespace std;

class FenwickTree {
    private:
        int n;
        vector<int> t;
    
        inline int g(int i) {return i & (i + 1);}

        inline int h(int i) {return i | (i + 1);}

        int rsq(int r) {
            int sumVal = 0;

            while(r >= 0) {
                sumVal += t[r];
                r = g(r) - 1;
            }

            return sumVal;
        }

    public:

        FenwickTree(int n_):
            n(n_),
            t(n, 0) {}

        FenwickTree(const vector<int> &a):
            n(a.size()),
            t(n) {
                for(int i = 0;i < n;i++)
                    update(i, a[i]);
            }

        ~FenwickTree() {}

        inline int rsq(int l, int r) {
            return rsq(r) - (l > 0 ? rsq(l - 1) : 0);
        }

        void update(int i, int x) {
            while(i < n) {
                t[i] += x;
                i = h(i);
            }
        }
};

class FenwickTreePointQry {
    private:
        int n;
        FenwickTree ft;
    public:
        FenwickTreePointQry(int n_):
            n(n_),
            ft(n) {}

        FenwickTreePointQry(const vector<int> &a):
            n(a.size()),
            ft(n) {
                for(int i = 0;i < n;i++)
                    rangeUpdate(i, i, a[i]);
            }

        ~FenwickTreePointQry() {}

        inline void rangeUpdate(int l, int r, int x) {
            ft.update(l, x);
            if(r < n - 1)
                ft.update(r + 1, -x);
        }

        inline int pointQuery(int i) {
            return ft.rsq(0, i);
        }
};

class FenwickTreeRangeUpdate {
    private:
        int n;
        FenwickTree f1, f2;
    
        inline int sum(int r) {
            return f1.rsq(0, r) + f2.rsq(0, r) * r;
        }

    public:

        FenwickTreeRangeUpdate(int n_):
            n(n_),
            f1(n),
            f2(n) {}

        FenwickTreeRangeUpdate(const vector<int> &a):
            n(a.size()),
            f1(n),
            f2(n) {
                for(int i = 0;i < n;i++)
                    update(i, i, a[i]);
            }

        ~FenwickTreeRangeUpdate() {}

        inline int sum(int l, int r) {
            return sum(r) - (l > 0 ? sum(l - 1) : 0);
        }

        void update(int l, int r, int x) {
            f1.update(l, (1 - l) * x);
            f2.update(l, x);
            if(r < n - 1) {
                f1.update(r + 1, r * x);
                f2.update(r + 1, -x);
            }
        }
};

void readArr(vector<int> &a) {
    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

void performOp1() {
    vector<int> a;
    readArr(a);

    FenwickTree ft(a);
    string qry;
    while(cin >> qry) {
        if(qry == "update") {
            int i, x;
            cin >> i >> x;
            ft.update(i, x);
        }
        else if(qry == "sum") {
            int l, r;
            cin >> l >> r;
            cout << ft.rsq(l, r) << "\n";
        }
        else if(qry == "done")
            break;
    }
}

void performOp2() {
    vector<int> a;
    readArr(a);

    FenwickTreePointQry ft(a);
    string qry;
    while(cin >> qry) {
        if(qry == "update") {
            int l, r, x;
            cin >> l >> r >> x;
            ft.rangeUpdate(l, r, x);
        }
        else if(qry == "sum") {
            int i;
            cin >> i;
            cout << ft.pointQuery(i) << "\n";
        }
        else if(qry == "done")
            break;
    }
}

void performOp3() {
    vector<int> a;
    readArr(a);

    FenwickTreeRangeUpdate ft(a);
    string qry;
    while(cin >> qry) {
        if(qry == "update") {
            int l, r, x;
            cin >> l >> r >> x;
            ft.update(l, r, x);
        }
        else if(qry == "sum") {
            int l, r;
            cin >> l >> r;
            cout << ft.sum(l, r) << "\n";
        }
        else if(qry == "done")
            break;
    }
}

int main() {
    string opType;
    cin >> opType;
    if(opType == "range_query") performOp1();
    else if(opType == "point_query") performOp2();
    else if(opType == "range_update") performOp3();

    return 0;
}