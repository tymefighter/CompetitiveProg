#include<iostream>

using namespace std;

long long A, B, C, D;

void solve() {

    long long num = 0;
    for(long long i = A + B;i <= B + C;i++) {
        if(C >= i)
            continue;

        long long numChoice = max(
            min(i - A, C) - max(i - B, B) + 1,
            0ll
        );

        if(i <= D)
            num += numChoice * (i - C);
        else
            num += numChoice * (D - C + 1);
    }

    cout << num << "\n";
}

int main() {

    cin >> A >> B >> C >> D;
    solve();
    return 0;
}