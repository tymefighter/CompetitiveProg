#include<iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        if(n <= 30)
            cout << "NO\n";
        else {
            cout << "YES\n";
            if(n == 31)
                cout << "6 10 14 1\n";
            else {
                int val = n - 30;
                if(val == 6 || val == 10 || val == 14) {
                    val = n - 31;
                    cout << "6 10 15 " << val << "\n";
                }
                else
                    cout << "6 10 14 " << val << "\n";
            }
        }
    }

    return 0;
}