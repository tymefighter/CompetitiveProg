#include<iostream>

using namespace std;

const int N = 200005;
int n, a[N];

void readInput() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
}

int solve() {
    if(n == 1)
        return 1;
    
    int prevMax = -1, ans = 0;

    for(int i = 0;i < n - 1;i++) {
        if(a[i] > prevMax && a[i] > a[i + 1])
            ans ++;

        prevMax = max(prevMax, a[i]);
    }

    ans += (a[n - 1] > prevMax ? 1 : 0);

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