#include <iostream>
#include <set>

using namespace std;

const int N = 105;
int n, m;
int bottom[N];
set<int> leftSet;

void readInput() {
    scanf("%d %d ", &n, &m);
    
    for(int i = 0;i < n;i++)
        scanf("%d ", &bottom[i]);

    leftSet.clear();
    for(int i = 0;i < m;i++) {
        int x;
        scanf("%d ", &x);
        leftSet.insert(x);
    }
}

void solve() {
    int ans = 0;
    for(int i = 0;i < n;i++) {
        if(leftSet.find(bottom[i]) != leftSet.end())
            ans ++;
    }

    printf("%d\n", ans);
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
