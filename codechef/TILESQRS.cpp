#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int N = 205;
int n, q, numSq;
int arr[N][N];

void initArr() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            arr[i][j] = -1;
    }
}

bool isOdd(int x) {return (x & 1) != 0;}

inline int askQuery(int i, int j) {
    cout << "1 " << i + 1 << " " << j + 1 << endl;

    int newNumSq;
    cin >> newNumSq;

    if(newNumSq == -1) exit(0);

    return newNumSq;
}

void getTop() {
    static vector<pair<int, int> > indexOps = {
        {0, 1}, {1, 1}, {0, 1}, {1, 0},
        {1, 1}, {0, 1}, {1, 1}
    };

    for(int i = 0;i + 1 < n;i += 2) {
        int newNumSq = askQuery(0, i);
        if(newNumSq != numSq) {
            arr[0][i] = (newNumSq < numSq ? 1 : 0);
            numSq = newNumSq;
        }
        else {
            for(pair<int, int> idxOp : indexOps) {
                int r = idxOp.first, c = i + idxOp.second;
                numSq = askQuery(r, c);
                
                int newNumSq = askQuery(0, i);
                if(newNumSq != numSq) {
                    arr[0][i] = (newNumSq < numSq ? 1 : 0);
                    numSq = newNumSq;
                    break;
                }
            }
        }

        arr[1][i] = 1;
        arr[0][i + 1] = 1;
        arr[1][i + 1] = 0;
    }

    if(isOdd(n)) {
        numSq = askQuery(0, n - 2);
        arr[0][n - 2] = 0;

        numSq = askQuery(1, n - 2);
        arr[1][n - 2] = 1;
        /*
            / ?
            \ ?
        */

        int newNumSq = askQuery(0, n - 1);
        if(newNumSq != numSq) {
            arr[0][n - 1] = (newNumSq < numSq ? 0 : 1);
            numSq = newNumSq;
        }
        else {
            numSq = askQuery(1, n - 1);
            newNumSq = askQuery(0, n - 1);
            arr[0][n - 1] = (newNumSq < numSq ? 0 : 1);
            numSq = newNumSq;
        }
        arr[1][n - 1] = 0;
    }
}

void getLeftSide() {
    static vector<pair<int, int> > indexOps = {
        {0, 1}, {1, 1}, {0, 1}, {1, 0},
        {1, 1}, {0, 1}, {1, 1}
    };

    for(int i = 2;i + 1 < n;i += 2) {

        int newNumSq = askQuery(i, 0);
        if(newNumSq != numSq) {
            arr[i][0] = (newNumSq < numSq ? 1 : 0);
            numSq = newNumSq;
        }
        else {

            for(pair<int, int> idxOp : indexOps) {
                int r = i + idxOp.first, c = idxOp.second;
                numSq = askQuery(r, c);
                
                int newNumSq = askQuery(i, 0);
                if(newNumSq != numSq) {
                    arr[i][0] = (newNumSq < numSq ? 1 : 0);
                    numSq = newNumSq;
                    break;
                }
            }
        }

        arr[i][1] = 1;
        arr[i + 1][0] = 1;
        arr[i + 1][1] = 0;
    }

    if(isOdd(n)) {
        if(arr[n - 2][0] == 1) {
            numSq = askQuery(n - 2, 0);
            arr[n - 2][0] = 0;
        }

        if(arr[n - 2][1] == 0) {
            numSq = askQuery(n - 2, 1);
            arr[n - 2][1] = 1;
        }
        /*
            / \
            ? ?
        */

        int newNumSq = askQuery(n - 1, 0);
        if(newNumSq != numSq) {
            arr[n - 1][0] = (newNumSq < numSq ? 0 : 1);
            numSq = newNumSq;
        }
        else {
            numSq = askQuery(n - 1, 1);
            newNumSq = askQuery(n - 1, 0);
            arr[n - 1][0] = (newNumSq < numSq ? 0 : 1);
            numSq = newNumSq;
        }
        arr[n - 1][1] = 0;
    }
}

void getAll() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(arr[i][j] != -1) continue;

            if(arr[i - 1][j - 1] == 1) {
                numSq = askQuery(i - 1,j - 1);
                arr[i - 1][j - 1] = 0;
            }
            
            if(arr[i][j - 1] == 0) {
                numSq = askQuery(i, j - 1);
                arr[i][j - 1] = 1;
            }

            if(arr[i - 1][j] == 0) {
                numSq = askQuery(i - 1, j);
                arr[i - 1][j] = 1;
            }

            int newNumSq = askQuery(i, j);
            arr[i][j] = (newNumSq < numSq ? 1 : 0);
            numSq = newNumSq;
        }
    }
}

void printQuery() {
    cout << "2" << endl;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int verdict;
    cin >> verdict;
    if(verdict == -1) exit(0);
}

void solve() {
    initArr();
    getTop();
    getLeftSide();
    getAll();
    printQuery();
}

int main() {

    int t;
    cin >> t;

    while(t --) {
        cin >> n >> q >> numSq;
        solve();
    }

    return 0;
}
