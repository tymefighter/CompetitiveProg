#include<iostream>

using namespace std;

long long a, K;

int getMinMaxProd() {
    long long temp_a = a;
    int minDig = temp_a % 10, maxDig = temp_a % 10;
    temp_a /= 10;

    while(temp_a) {
        minDig = min(minDig, static_cast<int>(temp_a % 10));
        maxDig = max(maxDig, static_cast<int>(temp_a % 10));
        temp_a /= 10;
    }

    return minDig * maxDig;
}

void solve() {
    for(int i = 0;i < K - 1;i++) {
        int prod = getMinMaxProd();
        if(prod == 0)
            break;

        a = a + static_cast<long long>(prod);
    }

    cout << a << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t --) {
        cin >> a >> K;
        solve();
    }
    return 0;
}