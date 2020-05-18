#include<iostream>

using namespace std;

int n, k;
int a[200005];

void readInput() {
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
}

int solve() {
    int prev_value = k + 1;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] == prev_value - 1) {
            prev_value = a[i];
            if(prev_value == 1) {
                prev_value = k + 1;
                ans ++;
            }
        }
        else if(a[i] == k)
            prev_value = k;
        else
            prev_value = k + 1;
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