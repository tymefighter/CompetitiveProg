#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100005;
int n, q;
int a[N];

void readInput() {
    scanf("%d %d ", &n, &q);
    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);

    sort(a, a + n);
}

set<long long> valueSet;

void buildValueSet(int startIdx, int endIdx) {

    if(startIdx == endIdx) {
        valueSet.insert(a[startIdx]);
        return;
    }

    long long sumVal = 0;
    int breakIdx, midVal = (a[startIdx] + a[endIdx]) / 2;

    for(int i = startIdx;i <= endIdx;i++) {
        if(a[i] <= midVal)
            breakIdx = i;

        sumVal += a[i];
    }

    valueSet.insert(sumVal);

    if(breakIdx < endIdx) {
        buildValueSet(startIdx, breakIdx);
        buildValueSet(breakIdx + 1, endIdx);
    }
}

void solve() {
    valueSet.clear();
    buildValueSet(0, n - 1);

    while(q --) {
        int s;
        scanf("%d ", &s);

        if(valueSet.find(s) != valueSet.end())
            printf("Yes\n");
        else
            printf("No\n");
    }
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
