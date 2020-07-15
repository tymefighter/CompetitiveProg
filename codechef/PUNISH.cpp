#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t --) {
        long long n, k;
        cin >> n >> k;
        if(k == 1)
            cout << "1\n";
        else {
            k --;
            long long val = k % (2 * n - 2);
            if(val >= n)
                val = 2 * (n - 1) - val;
            cout << val + 1 << "\n";
        }
    }

    return 0;
}