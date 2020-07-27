#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 800005;

int n;
pair<long long, long long> a[N]; // (position, height)
long long p[N], h[N], dp[N][2];

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++)
        scanf("%lld %lld ", &a[i].first, &a[i].second);
}

void preProcess() {
    sort(a, a + n); // sort by position
    for(int i = 0;i < n;i++) {
        p[i] = a[i].first;
        h[i] = a[i].second;
    }
}

void computeDP() {
    // maxPos[pos] : maximum length we can have that
    // ends at position pos
    unordered_map<long long, long long> maxPos;

    dp[0][0] = dp[0][1] = h[0];
    maxPos[p[0]] = maxPos[p[0] + h[0]] = h[0];

    for(int i = 1;i < n;i++) {
        // Use maxPos
        if(maxPos.find(p[i] - h[i]) != maxPos.end())
            dp[i][0] = maxPos[p[i] - h[i]] + h[i];
        else
            dp[i][0] = h[i];

        if(maxPos.find(p[i]) != maxPos.end()) {
            dp[i][1] = maxPos[p[i]] + h[i];
            maxPos[p[i]] = max(maxPos[p[i]], dp[i][0]);
        }
        else {
            dp[i][1] = h[i];
            maxPos[p[i]] = dp[i][0];
        }            
        
        if(maxPos.find(p[i] + h[i]) == maxPos.end())
            maxPos[p[i] + h[i]] = dp[i][1];
        else
            maxPos[p[i] + h[i]] = max(maxPos[p[i] + h[i]], dp[i][1]);
    }
}

long long solve() {
    if(n == 1)
        return a[0].second;

    preProcess();
    computeDP();

    long long ans = 0;

    for(int i = 0;i < n;i++)
        ans = max(ans, max(dp[i][0], dp[i][1]));

    return ans;
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