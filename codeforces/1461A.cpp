#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t --) {
        int n, k;
        cin >> n >> k;

        string ans;
        for(int i = 0;i < n;i++)
            ans.push_back(static_cast<char>('a' + (i % 3)));

        cout << ans << "\n";
    }

    return 0;
}
