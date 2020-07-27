#include<iostream>

using namespace std;

const int N = 100005;
int n, a[N];
int numOnePrefix;
bool foundBreak;

void read() {
    cin >> n;
    numOnePrefix = 0;
    foundBreak = false;
    for(int i = 0;i < n;i++) {
        cin >> a[i];

        if(!foundBreak && a[i] == 1)
            numOnePrefix ++;
        else if(a[i] != 1)
            foundBreak = true;
    }
}

void solve() {
    if(!foundBreak) {
        if(numOnePrefix % 2 == 0)
            cout << "Second\n";
        else
            cout << "First\n";
    }
    else {
        if(numOnePrefix % 2 == 0)
            cout << "First\n";
        else
            cout << "Second\n";
    }
}

int main() {

    int t;
    cin >> t;
    while(t --) {
        read();
        solve();
    }

    return 0;
}