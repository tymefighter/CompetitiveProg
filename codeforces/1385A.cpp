#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t --) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == y && y >= z) {
            cout << "YES\n";
            cout << x << " " << z << " " << z << "\n";
        }
        else if(y == z && y >= x) {
            cout << "YES\n";
            cout << x << " " << x << " " << z << "\n";
        }
        else if(x == z && z >= y) {
            cout << "YES\n";
            cout << y << " " << x << " " << y << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}