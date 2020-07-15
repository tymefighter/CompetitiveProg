#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 200005;
int n;
long long minVal, a[N], b[N];;

unordered_map<long long, int> m1, m2;
unordered_set<long long> s;
vector<long long> x, y;

void reset() {
    x.clear();
    y.clear();
    m1.clear();
    m2.clear();
    s.clear();
    minVal = -1;
}

void readInput() {
    scanf("%d ", &n);
    for(int i = 0;i < n;i++) {
        scanf("%lld ", &a[i]);

        s.insert(a[i]);
        if(m1.find(a[i]) == m1.end())
            m1[a[i]] = 0;

        m1[a[i]] ++;

        if(i == 0)
            minVal = a[0];
        else
            minVal = min(minVal, a[i]);
    }

    for(int i = 0;i < n;i++) {
        scanf("%lld ", &b[i]);

        s.insert(b[i]);
        if(m2.find(b[i]) == m2.end())
            m2[b[i]] = 0;

        m2[b[i]] ++;
        minVal = min(minVal, b[i]);
    }
}

bool getExclusive() {
    for(long long val : s) {
        int ct;

        if(m1.find(val) == m1.end())
            ct = - m2[val];
        else if(m2.find(val) == m2.end())
            ct = m1[val];
        else 
            ct = m1[val] - m2[val];

        if(abs(ct) % 2 == 1)
            return false;

        if(ct > 0) {
            while(ct --)
                x.push_back(val);
        }
        else if(ct < 0) {
            while(ct ++)
                y.push_back(val);
        }
    }

    return x.size() == y.size();
}

void solve() {
    long long cost = 0;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());

    for(int i = 0;i < x.size();i += 2) {
        long long val = min(x[i], y[i]);
        if(val < 2 * minVal)
            cost += val;
        else
            cost += 2 * minVal;
    }

    printf("%lld\n", cost);
}

int main() {

    int t;
    scanf("%d ", &t);

    while(t --) {
        reset();
        readInput();
        if(getExclusive())
            solve();
        else
            printf("-1\n");
    }

    return 0;
}