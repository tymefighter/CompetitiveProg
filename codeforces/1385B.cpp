#include<iostream>

using namespace std;

const int N = 105;
int n;
bool seen[N];

void readSolve() {
    cin >> n;
    n *= 2;
    for(int i = 1;i <= n;i++)
        seen[i] = false;

    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(!seen[x]) {
            cout << x << " ";
            seen[x] = true;
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --)
        readSolve();

    return 0;
}