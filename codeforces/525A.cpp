#include <iostream>

using namespace std;

int keyCount[26];

void readSolve() {
    int n;
    int ans = 0;

    cin >> n;
    n --;
    for(int i = 0;i < 26;i++)
        keyCount[i] = 0;

    for(int i = 0;i < n;i++) {
        char key, door;
        cin >> key >> door;
        
        keyCount[key - 'a'] ++;
        if(keyCount[door - 'A'] == 0)
            ans ++;
        else
            keyCount[door - 'A'] --;
    }

    cout << ans << "\n";
}

int main() {
    readSolve();
    return 0;
}
