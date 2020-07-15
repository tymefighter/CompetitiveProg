#include<iostream>

using namespace std;

inline long long sq(long long x) {return x * x;}

int main() {
    int t;
    cin >> t;
    while(t --) {
        long long x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;
        long long centerDistSq = sq(x1 - x2) + sq(y1 - y2);
        long long radiusSumSq = sq(r1 + r2);

        cout 
            << (centerDistSq <= radiusSumSq ? "YES" : "NO")
            << "\n";
    }

    return 0;
}