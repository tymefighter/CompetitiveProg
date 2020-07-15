#include<iostream>
#include<set>
#include<cassert>

using namespace std;

const int N = 100005;
int n;
long long maxVal, x, a[N];
multiset<long long> s;

void readInput() {
    scanf("%d %lld ", &n, &x);

    maxVal = 0;
    s.clear();
    for(int i = 0;i < n;i++) {
        scanf("%lld ", &a[i]);
        maxVal = max(maxVal, a[i]);
        s.insert(a[i]);
    }
}

void solve() {

    if(x >= maxVal) {
        printf("%d\n", n);
        return;
    }

    long long ans = 0;
    while(x < maxVal) {
        auto it = s.lower_bound(x);
        assert(it != s.end());
        
        if(*it == x) {
            s.erase(it);
            x = x * 2;
        }
        else {
            if(it != s.begin() && 2 * (*(--it)) >= x) {
                x = 2 * (*it);
                s.erase(it);
            }
            else
                x = x * 2;
        }
        
        ans ++;
    }
    ans += s.size();
    printf("%lld\n", ans);
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