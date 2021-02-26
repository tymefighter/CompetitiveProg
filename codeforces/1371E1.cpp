#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 2005;
int n, p;
int a[N], max_a;

void readInput() {
    scanf("%d %d ", &n, &p);
    max_a = 0;
    for(int i = 0;i < n;i++) {
        scanf("%d ", &a[i]);
        max_a = max(max_a, a[i]);
    }
}

bool notDivPermutation(int x) {
    int numLessEq = 0, i = 0, idx = 0;

    while(idx < n) {
        while(i < n && a[i] <= x) {
            numLessEq ++;
            i ++;
        }

        if(numLessEq % p == 0)
            return false;

        x ++;
        numLessEq --;
        idx ++;
    }

    return true;
}

void solve() {
    sort(a, a + n);
    vector<int> ans;
    for(int x = 1;x < max_a;x++) {
        if(notDivPermutation(x))
            ans.push_back(x);
    }

    printf("%lu\n", ans.size());
    for(int x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    readInput();
    solve();
    return 0;
}