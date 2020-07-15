#include<iostream>

using namespace std;

const int N = 505;
int n, a[N], b[N];
int numZero, numOne;
bool isSorted;

void readInput() {
    cin >> n;

    numZero = numOne = 0;
    isSorted = true;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(i > 0 && a[i] < a[i - 1])
            isSorted = false;
    }

    for(int i = 0;i < n;i++) {
        cin >> b[i];
        if(b[i] == 0)
            numZero ++;
        else
            numOne ++;
    }
}

bool solve() {
    if(isSorted)
        return true;
    return (numZero > 0 && numOne > 0);
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        if(solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}