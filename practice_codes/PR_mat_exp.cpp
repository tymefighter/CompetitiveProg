#include<iostream>
#include<vector>

using namespace std;

class MatError {
    private:
        string msg;
    public:
        MatError(const string msg_):
            msg(msg_) {}

        ~MatError() {}

        string get() {return msg;}
};

class Matrix {
    private:
        int n, m;
        vector<vector<long long> > a;
    public:

        Matrix():
            n(0),
            m(0),
            a(0) {}

        Matrix(int n_, int m_):
            n(n_),
            m(m_),
            a(vector<vector<long long> > (n, vector<long long>(m, 0))) {}

        Matrix(const Matrix &mat):
            n(mat.n),
            m(mat.m),
            a(mat.a) {}

        ~Matrix() {}

        inline long long& operator() (int i, int j) {
            if(i < 0 || i >= n || j < 0 || j >= m)
                throw *(new MatError("Index out of range"));
            
            return a[i][j];
        }

        const Matrix& operator= (const Matrix &mat) {
            n = mat.n;
            m = mat.m;
            a = mat.a;
            return *this;
        }

        inline pair<int, int> shape() {return {n, m};}
};

ostream& operator<< (ostream& os, Matrix &a) {
    int n = a.shape().first;
    int m = a.shape().second;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            os << a(i, j) << " ";
        os << "\n";
    }

    return os;
}

void identity(int n, Matrix &a) {

    a = Matrix(n, n);

    for(int i = 0;i < n;i++)
        a(i, i) = 1;
}

void matmul(Matrix &a, Matrix &b, Matrix &res, const long long mod) {
    pair<int, int> aShape = a.shape();
    pair<int, int> bShape = b.shape();

    assert(aShape.second == bShape.first);

    int n = aShape.first, m = bShape.second, p = aShape.second;
    res = Matrix(n, m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            res(i, j) = 0;
            for(int k = 0;k < p;k++)
                res(i, j) = (res(i, j) + (a(i, k) * b(k, j)) % mod) % mod;
        }
    }
}

void matExp(Matrix &a, long long pow, const long long mod) {
    if(pow == 0) {
        identity(a.shape().first, a);
        return;
    }
    else if(pow % 2 == 1) {
        Matrix b(a), c(a);
        matExp(b, pow - 1, mod);
        matmul(b, c, a, mod);
    }
    else {
        Matrix b(a);
        matExp(b, pow / 2, mod);
        Matrix c(b);
        matmul(b, c, a, mod);
    }
}

void readInput(Matrix &a, long long &pow, long long &mod) {
    int n;
    cin >> n >> pow >> mod;

    a = Matrix(n, n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cin >> a(i, j);
    }
}

int main() {

    Matrix a;
    long long pow, mod;

    readInput(a, pow, mod);
    matExp(a, pow, mod);
    cout << a;

    return 0;
}