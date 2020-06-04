#include<iostream>

using namespace std;

long long h, c, t;

inline double abs_d(double x) {
    return (x >= 0 ? x : -x);
}

long long solve() {
    if(2 * t <= h + c)
        return 2;

    long long i = (t - c) / (2 * t - (h + c));
    double val_i = (i * h + (i - 1) * c) / (double) (2 * i - 1);
    double val_i_next = ((i + 1) * h + i * c) / (double) (2 * i + 1);

    return 2 * (abs_d(val_i - (double)t) <= abs_d(val_i_next - (double)t) ? i : i + 1) - 1;
}

int main() {
    int tc;
    cin >> tc;
    while(tc --) {
        cin >> h >> c >> t;
        cout << solve() << "\n";
    }
    return 0;
}