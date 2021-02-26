#include <iostream>
#include <vector>

using namespace std;

int *readInput(int &n) {
    scanf("%d ", &n);
    int * a = new int[n];

    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);

    return a;
}

int computeArrayInfo(
    int n, int *a, 
    int &maxValue, long long &arraySum
) {
    maxValue = 0;
    arraySum = 0;

    for(int i = 0;i < n;i++) {
        maxValue = max(maxValue, a[i]);
        arraySum += a[i];
    }
    
    return maxValue;
}

long long ceilDivPos(long long u, long long v) {
    return (u + v - 1) / v;
}

long long computeMinimumBoxes(int n, int *a) {
    int maxValue;
    long long arraySum;
    computeArrayInfo(n, a, maxValue, arraySum);

    long long k = max(
        ceilDivPos(arraySum, n - 1), 
        static_cast<long long>(maxValue)
    );

    return k * (n - 1) - arraySum;
}


int main() {

    int testCases;
    scanf("%d ", &testCases);

    while(testCases --) {
        int n;
        int *a = readInput(n);
        printf("%lld\n", computeMinimumBoxes(n, a));

        delete [] a;
    }

    return 0;
}
