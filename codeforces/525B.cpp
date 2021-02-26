#include <iostream>

using namespace std;

const int N = 200005;
string s;
int m, n, ct[N];

void readSolve() {
    cin >> s;
    n = s.size();

    for(int i = 0;i <= n / 2;i++)
        ct[i] = 0;

    cin >> m;
    for(int i = 0;i < m;i++) {
        int idx;
        cin >> idx;
        ct[idx] ++;
    }

    for(int i = 2;i <= n / 2;i ++)
        ct[i] += ct[i - 1];

    for(int i = 1;i <= n / 2;i++) {
        if(ct[i] % 2 == 1) {
            int idx = i - 1;
            swap(s[idx], s[n - idx - 1]);
        }
    }

    cout << s << "\n";
}

int main() {
    readSolve();
    return 0;
}
