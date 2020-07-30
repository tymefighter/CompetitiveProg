#include<iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        int num8 = n / 4 + (n % 4 != 0 ? 1 : 0);
        int num9 = n - num8;

        for(int i = 0;i < num9;i++)
            cout << "9";
        for(int i = 0;i < num8;i++)
            cout << "8";
        cout << "\n";
    }

    return 0;
}