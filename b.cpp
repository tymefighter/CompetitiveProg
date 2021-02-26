#include <iostream>
#include <set>

using namespace std;

const int N = 1005;
int n, a[N];

void readSolve() {
    cin >> n;
    bool exist = false;

    set<int> s;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(s.find(x) != s.end())
            exist = true;
        s.insert(x);
    }

    cout << (exist ? "YES" : "NO") << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t --)
        readSolve();

    return 0;
}
