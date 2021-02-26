#include <iostream>
#include <algorithm>

using namespace std;

const int LARGE_VALUE = static_cast<int>(1e9 + 1);

int main() {

    int n[3];
    long long sumVal[3] = {0, 0, 0}, totalSum = 0;
    int minVal[3] = {LARGE_VALUE, LARGE_VALUE, LARGE_VALUE};

    for(int idx = 0;idx < 3;idx++)
        scanf("%d ", &n[idx]);

    for(int idx = 0;idx < 3;idx ++) {
        for(int i = 0;i < n[idx];i++) {
            int x;
            scanf("%d ", &x);

            sumVal[idx] += x;
            minVal[idx] = min(minVal[idx], x);
        }

        totalSum += sumVal[idx];
    }

    sort(minVal, minVal + 3);

    long long result = totalSum - 2 * min(
        min(sumVal[0], sumVal[1]),
        min(sumVal[2], static_cast<long long>(minVal[0] + minVal[1]))
    );

    printf("%lld\n", result);

    return 0;
}
