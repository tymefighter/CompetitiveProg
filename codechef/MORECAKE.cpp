#include<iostream>

using namespace std;

long long bin_exp(long long x, long long n) {
    if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return bin_exp(x, n - 1) * x;
    else {
        long long val = bin_exp(x, n / 2);
        return val * val;
    }
}

int main() {

    int t;
    cin >> t;

    long long totalSum = 0;
    while(t --) {
        long long S, N, K, R;
        cin >> S >> N >> K >> R;
        long long val = S - (R > 1 ? K * ((bin_exp(R, N) - 1) / (R - 1)) : N * K);
        totalSum += val;

        if(val >= 0)
            cout << "POSSIBLE " << val << "\n";
        else
            cout << "IMPOSSIBLE " << -val << "\n";
    }

    if(totalSum >= 0)
        cout << "POSSIBLE\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}