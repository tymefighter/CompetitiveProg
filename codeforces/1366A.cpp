#include<iostream>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t --) {
        long long a, b;
        cin >> a >> b;
        if(a < b)
            swap(a, b);

        if(a >= 2 * b)
            cout << b << "\n";
        else {
            long long diff = a - b;
            a = b = 2 * b - a;
            long long v1 = (2 * a) / 3, v2 = (2 * a - 1) / 3;
            cout << diff + max (
                v1 % 2 == 0 ? v1 : v1 - 1,
                v2 % 2 == 1 ? v2 : v2 - 1
            ) << "\n";
        }
    }
    return 0;
}