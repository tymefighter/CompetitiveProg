#include<iostream>

using namespace std;

void readSolve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        x = abs(x);
        cout << (i % 2 == 0 ? x : -x) << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readSolve();
    }
    return 0;
}