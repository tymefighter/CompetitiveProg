#include<iostream>

using namespace std;

const int N = 200005;
int n, a[N];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

int solve() {
    bool arraySorted = true, noCorrect = true;

    for(int i = 0;i < n;i++) {
        if(a[i] != i + 1)
            arraySorted = false;
        else
            noCorrect = false;
    }

    if(arraySorted)
        return 0;
    else if(noCorrect)
        return 1;

    bool foundNonCorrect = false;
    bool foundCorrectAfterNon = false;

    for(int i = 0;i < n;i++) {
        if(a[i] == i + 1) {
            if(foundNonCorrect)
                foundCorrectAfterNon = true;
        }
        else {
            if(foundCorrectAfterNon)
                return 2;
            foundNonCorrect = true;
        }
    }

    return 1;
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        readInput();
        cout << solve() << "\n";
    }

    return 0;
}