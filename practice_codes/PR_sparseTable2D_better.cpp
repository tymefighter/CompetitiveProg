#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class SparseTable2D {
    private:
        int n, m, pn, pm;
        vector<vector<vector<vector<int> > > > st;
    public:
        SparseTable2D(const vector<vector<int> > &a):
            n(a.size()),
            m(a[0].size()),
            pn(log2(n)),
            pm(log2(m)),
            st (
                pn + 1, 
                vector<vector<vector<int> > > (
                    n,
                    vector<vector<int> > (
                        pm + 1,
                        vector<int> (m)
                    )
                )
            ){
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < n;j++)
                        st[0][i][0][j] = a[i][j];

                    for(int pj = 1;pj <= pm;pj++) {
                        for(int j = 0;j + (1 << pj) <= m;j++)
                            st[0][i][pj][j] 
                                = min(
                                    st[0][i][pj - 1][j],
                                    st[0][i][pj - 1][j + (1 << (pj - 1))]
                                );
                    }
                }

                for(int pi = 1;pi <= pn;pi++) {
                    for(int i = 0;i + (1 << pi) <= n;i++) {
                        for(int pj = 0;pj <= pm;pj++) {
                            for(int j = 0;j + (1 << pj) <= m;j++) {
                                st[pi][i][pj][j]
                                    = min(
                                        st[pi - 1][i][pj][j],
                                        st[pi - 1][i + (1 << (pi - 1))][pj][j]
                                    );
                            }
                        }
                    }
                }
            }

        ~SparseTable2D() {}

        int minimum(int r1, int c1, int r2, int c2) {
            int rPow = log2(r2 - r1 + 1);
            int cPow = log2(c2 - c1 + 1);

            int valUp = min (
                st[rPow][r1][cPow][c1],
                st[rPow][r1][cPow][c2 - (1 << cPow) + 1]
            );

            int valDown = min (
                st[rPow][r2 - (1 << rPow) + 1][cPow][c1],
                st[rPow][r2 - (1 << rPow) + 1][cPow][c2 - (1 << cPow) + 1]
            );

            return min(valUp, valDown);
        }
};

void readInput(vector<vector<int> > &a, int &p, int &q) {
    int n, m;
    cin >> n >> m >> p >> q;

    a.clear();
    a.assign(n, vector<int>(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    }
}

void minSubmatrices(
    const vector<vector<int> > &a,
    const int p,
    const int q
) {
    int n = a.size(), m = a[0].size();
    SparseTable2D st(a);

    for(int i = 0;i + p <= n;i++) {
        for(int j = 0;j + q <= m;j++)
            cout << st.minimum(i, j, i + p - 1, j + q - 1) << " ";
        cout << "\n";
    }
}

int main() {

    vector<vector<int> > a;
    int p, q;

    readInput(a, p, q);
    minSubmatrices(a, p, q);

    return 0;
}