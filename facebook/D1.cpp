#include<iostream>
#include<set>

using namespace std;

const int N = 1000005;

int n;
long long m, c[N];
long long dp[N];

void readInput() {
    scanf("%d %lld ", &n, &m);

    for(int i = 0;i < n;i++)
        scanf("%lld ", &c[i]);
}

long long solve() {

    if(m >= n - 1)
        return 0;

    // Would contain atmost m elements
    // It contains cost of atmost m previous cities
    // at which we can refuel to reach current city
    multiset<long long> s;

    dp[0] = 0;
    for(int i = 1;i < m;i++) {
        dp[i] = 0;
        if(c[i] > 0)
            s.insert(c[i]);
    }
    dp[m] = 0;
    if(c[m] > 0)
        s.insert(c[m]);

    for(int i = m + 1;i < n;i++) {
        // We cannot reach i
        if(s.size() == 0) {
            dp[i] = -1;
            continue;
        }

        // Add to window
        dp[i] = *(s.begin());
        if(c[i] > 0)
            s.insert(dp[i] + c[i]);

        // Remove from window
        if(c[i - m] > 0) {
            long long val = dp[i - m] + c[i - m];
            multiset<long long>::iterator it = s.find(val);
            s.erase(it);
        }
    }

    return dp[n - 1];
}

int main() {
    int t;
    scanf("%d ", &t);

    for(int i = 1;i <= t;i++) {
        readInput();
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}