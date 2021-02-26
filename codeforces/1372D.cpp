#include<iostream>

using namespace std;

const int N = 200005;
int n;
int a[N];
long long leftAltSum[N], rightAltSum[N];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);
}

void computeSums() {
    leftAltSum[0] = a[0];
    rightAltSum[n - 1] = a[n - 1];
    if(n > 1) {
        leftAltSum[1] = a[1];
        rightAltSum[n - 2] = a[n - 2];
    }

    for(int i = 2;i < n;i++)
        leftAltSum[i] = a[i] + leftAltSum[i - 2];

    for(int i = n - 3;i >= 0;i--)
        rightAltSum[i] = a[i] + rightAltSum[i + 2];
}

void solve() {
    computeSums();
    long long maxSum = 0;
    for(int i = 0;i < n - 1;i++)
        maxSum = max(maxSum, leftAltSum[i] + rightAltSum[i + 1]);

    long long evenSum = 0;
    for(int i = 0;i < n;i += 2)
        evenSum += a[i];

    maxSum = max(maxSum, evenSum);
    printf("%lld\n", maxSum);
}

int main() {
    readInput();
    solve();
    return 0;
}