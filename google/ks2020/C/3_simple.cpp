#include<iostream>
#include<cmath>

using namespace std;

int n, a[100005];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

bool is_perfect_square(int x) {
    int val = static_cast<int>(sqrt(x));
    return val * val == x;
}

int solve() {
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int val = 0, j = i;
        while(j >= 0) {
            val += a[j];
            j --;
            if(val >= 0 && is_perfect_square(val))
                ans ++;
        }
    }

    return ans;
}

int main() {

    int t;
    cin >> t;
    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}