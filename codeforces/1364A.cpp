#include<iostream>

using namespace std;

const int N = 55;
int n, m, a[N][N];

void readInput() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    }
}

bool solve() {
    int numR = 0, numC = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 1) {
                numR ++;
                break;
            }
        }
    }
    numR = n - numR;

    for(int j = 0;j < m;j++) {
        for(int i = 0;i < n;i++) {
            if(a[i][j] == 1) {
                numC ++;
                break;
            }
        }
    }
    numC = m - numC;

    return (min(numR, numC) % 2 == 1);
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        readInput();
        if(solve())
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
    return 0;
}