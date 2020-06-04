#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 200005;
int n, k, a[N], c[N], numGE[N];

void readInput() {
    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++)
        scanf("%d ", &a[i]);

    for(int i = 1;i <= k;i++) {
        scanf("%d ", &c[i]);
        numGE[i] = 0;
    }
}

void solve() {
    for(int i = 0;i < n;i++)
        numGE[a[i]] ++;
    for(int i = k - 1;i >= 1;i--)
        numGE[i] += numGE[i + 1];
        
    int numTC = 0;
    for(int i = 1;i <= k;i++)
        numTC = max(numTC, (numGE[i] % c[i] != 0 ? 1 : 0) + numGE[i] / c[i]);

    printf("%d\n", numTC);

    vector<vector<int> > t(numTC);
    sort(a, a + n);

    for(int i = 0;i < n;i++)
        t[i % numTC].push_back(a[i]);

    for(const vector<int> &v : t) {
        printf("%d ", static_cast<int>(v.size()));
        for(int x : v)
            printf("%d ", x);
        printf("\n");
    }
}

int main() {

    readInput();
    solve();

    return 0;
}