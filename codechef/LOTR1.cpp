#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t --) {
        long long M, N;
        cin >> M >> N;

        long long num = 9, ct = 0;
        while(num <= N) {
            ct ++;
            num = num * 10 + 9;
        }

        ct *= M;
        if(ct == 0)
            cout << "0 0\n";
        else
            cout << ct << " " << M << "\n";
    }

    return 0;
}