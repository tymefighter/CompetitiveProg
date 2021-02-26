#include <iostream>

using namespace std;

const int N = 300005;
int n, a[N], initArrayValue;

inline bool isHillOrValley(int idx) {
    if(idx <= 0 || idx >= n - 1) return false;

    return (
        (a[idx - 1] < a[idx] && a[idx] > a[idx + 1])
        ||
        (a[idx - 1] > a[idx] && a[idx] < a[idx + 1])
    );
}

void readInput() {
    scanf("%d ", &n);
    
    initArrayValue = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d ", &a[i]);

        initArrayValue += (isHillOrValley(i - 1) ? 1 : 0);
    }
}

int updateAndGetValue(int i, int newVal, int arrayValue) {
    int prevVal = a[i];
    a[i] = newVal;

    arrayValue += (isHillOrValley(i) ? 1 : 0);
    arrayValue += (isHillOrValley(i - 1) ? 1 : 0);
    arrayValue += (isHillOrValley(i + 1) ? 1 : 0);

    a[i] = prevVal;
    return arrayValue;
}

void solve() {
    int minValue = initArrayValue;

    for(int i = 0;i < n;i++) {
        int arrayValue = initArrayValue;

        arrayValue -= (isHillOrValley(i) ? 1 : 0);
        arrayValue -= (isHillOrValley(i - 1) ? 1 : 0);
        arrayValue -= (isHillOrValley(i + 1) ? 1 : 0);

        if(i > 0) {
            for(int j = -1;j <= 1;j++)
                minValue = min(
                    minValue, 
                    updateAndGetValue(
                        i, 
                        a[i - 1] + j, 
                        arrayValue
                ));
        }

        if(i < n - 1) {
            for(int j = -1;j <= 1;j++)
                minValue = min(
                    minValue, 
                    updateAndGetValue(
                        i, 
                        a[i + 1] + j, 
                        arrayValue
                ));
        }
    }

    printf("%d\n", minValue);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        readInput();
        solve();
    }

    return 0;
}
