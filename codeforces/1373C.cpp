#include<iostream>
#include<cstring>

using namespace std;

const int N = static_cast<int>(1e6 + 5);
int n;
char s[N];
int diff[N];        // diff[i] = num of minus([0..i]) - num of plus([0..i])
int prefixMax[N];   // prefixMax[i] = max(diff[j]) for j in [0..i]

void solve() {
    
    diff[0] = (s[0] == '-' ? 1 : -1);
    prefixMax[0] = diff[0];

    for(int i = 1;i < n;i++) {
        diff[i] = diff[i - 1] + (s[i] == '-' ? 1 : -1);
        prefixMax[i] = max(prefixMax[i - 1], diff[i]);
    }

    long long ans = 0;
    for(int i = 0;i <= n;i++) {
        int low = 0, high = n - 1, ansIdx = -1;

        while(low <= high) {
            int mid = (low + high) >> 1;

            if(prefixMax[mid] <= i) {
                ansIdx = max(ansIdx, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        ans += ansIdx + 1;
        if(ansIdx == n - 1)
            break;
        else
            ans ++;
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t --) {
        scanf("%s ", s);
        n = strlen(s);
        solve();
    }

    return 0;
}