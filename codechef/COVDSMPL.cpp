#include<iostream>

using namespace std;

const int N = 65;
int a[N][N];

bool getArr(int r1, int r2, int c1, int c2, int val) {
    int n = r2 - r1 + 1, m = c2 - c1 + 1;
    if(n == 1 && m == 1) {
        a[r1][c1] = val;
        return true;
    }

    if(val == 0) {
        for(int i = r1;i <= r2;i++) {
            for(int j = c1;j <= c2;j++)
                a[i][j] = 0;
        }
        return true;
    }

    if(n > 1) {
        int mid = (r1 + r2) >> 1, pass_value;
        cout << "1 " << r1 + 1 << " " << c1 + 1 << " " << mid + 1 << " " << c2 + 1 << endl;
        cin >> pass_value;
        if(pass_value == -1)
            return false;
        if(!getArr(r1, mid, c1, c2, pass_value))
            return false;
        if(!getArr(mid + 1, r2, c1, c2, val - pass_value))
            return false;
    }
    else {
        int mid = (c1 + c2) >> 1, pass_value;
        cout << "1 " << r1 + 1 << " " << c1 + 1  << " " << r2 + 1 << " " << mid + 1 << endl;
        cin >> pass_value;
        if(pass_value == -1)
            return false;
        if(!getArr(r1, r2, c1, mid, pass_value))
            return false;
        if(!getArr(r1, r2, mid + 1, c2, val - pass_value))
            return false;
    }

    return true;
}

bool solve(int n, int p) {
    int val;
    cout << "1 " << "1 1 " << n << " " << n << endl;
    cin >> val;
    if(val == -1)
        return false;
    
    if(!getArr(0, n - 1, 0, n - 1, val))
        return false;

    cout << "2" << endl;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    int is_correct;
    cin >> is_correct;
    if(is_correct == -1)
        return false;
    else
        return true;
}

int main() {

    int t;
    cin >> t;

    while(t --) {
        int n, p;
        cin >> n >> p;
        if(!solve(n, p))
            break;
    }

    return 0;
}