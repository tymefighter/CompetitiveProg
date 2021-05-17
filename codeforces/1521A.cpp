#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t --) {
        long long a, b;
        cin >> a >> b;

        if(b == 1) cout << "NO\n";
        else if(b == 2)
            cout 
            << "YES\n" 
            << a * 3 << " " << a << " " << a * 4
            << "\n";
        else cout 
            << "YES\n" 
            << a * (b - 1) << " " << a << " " << a * b 
            << "\n";
    }

    return 0;
}