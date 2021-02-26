#include<iostream>
#include<vector>

using namespace std;

class Fenwick2D {
    private:
        int n, m;
        vector<vector<int> > t;

        inline int g(int i) {return i & (i + 1);}

        inline int h(int i) {return i | (i + 1);}

        int sum(int r, int c) {
            int sumVal = 0, i = r, j;
            
            while(i >= 0) {
                j = c;
                while(j >= 0) {
                    sumVal += t[i][j];
                    j = g(j) - 1;
                }
                i = g(i) - 1;
            }

            return sumVal;
        }

    public:

        Fenwick2D(int n_, int m_):
            n(n_),
            m(m_),
            t(n, vector<int>(m, 0)) {}
        
        Fenwick2D(const vector<vector<int> > &a):
            n(a.size()),
            m(a[0].size()),
            t(n, vector<int>(m, 0)) {
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < m;j++)
                        update(i, j, a[i][j]);
                }
            }
        
        ~Fenwick2D() {}

        int sum(int r1, int c1, int r2, int c2) {
            return sum(r2, c2)
                - (c1 > 0 ? sum(r2, c1 - 1) : 0)
                - (r1 > 0 ? sum(r1 - 1, c2) : 0)
                + (r1 > 0 && c1 > 0 ? sum(r1 - 1, c1 - 1) : 0);
        }

        void update(int r, int c, int x) {
            int i = r, j;
            while(i < n) {
                j = c;
                while(j < m) {
                    t[i][j] += x;
                    j = h(j);
                }
                i = h(i);
            }
        }
};


void readArr(vector<vector<int> > &a) {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    }
}

void performOp() {
    vector<vector<int> > a;
    readArr(a);

    Fenwick2D ft(a);
    string qry;
    while(cin >> qry) {
        if(qry == "update") {
            int r, c, x;
            cin >> r >> c >> x;
            ft.update(r, c, x);
        }
        else if(qry == "sum") {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            cout << ft.sum(r1, c1, r2, c2) << "\n";
        }
        else if(qry == "done")
            break;
    }
}

int main() {
    performOp();
    return 0;
}