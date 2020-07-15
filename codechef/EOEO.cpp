#include<iostream>

using namespace std;

long long TS;

long long solve() {
    long long k = 0, temp = TS;
    while(temp % 2 == 0) {
        k ++;
        temp /= 2;
    }

    return TS / (1ll << (k + 1));
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> TS;
        cout << solve() << "\n";
    } 

    return 0;
}