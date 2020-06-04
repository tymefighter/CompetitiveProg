#include<iostream>
#include<unordered_set>

using namespace std;

void read_solve() {
    int n;
    unordered_set<int> s;

    scanf("%d ", &n);
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        x = (x + i) % n;
        if(x < 0)
            x += n;
        s.insert(x);
    }

    cout << (s.size() == n ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    scanf("%d ", &t);
    
    while(t --)
        read_solve();

    return 0;
}