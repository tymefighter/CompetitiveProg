#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

const long long INF = static_cast<long long>(1e16);
const int N = 1000005;

int n, s, t; // s: source, t: destination
vector<vector<int> > a;
bool alongPath[N];
long long m, c[N], dp[N], val[N];
/* 
    c[i]    : Cost of refueling at i
    dp[i]   : min cost to reach i from s if i is along path
    from s to t, else it is -1

    val[i]  : This is a very special thing
    for any node u on the path from s to t,
    and any node v s.t u is NOT an ancestor of
    v, we have: val[u] - val[v] = dist(u, v)
    This was thought by me....Ahmed Z D
*/

void readInput() {
    scanf("%d %lld %d %d ", &n, &m, &s, &t);
    s --, t --;
    a.clear();
    a.resize(n);

    int parent;
    scanf("%d %lld ", &parent, &c[0]);

    for(int i = 1;i < n;i++) {
        scanf("%d %lld ", &parent, &c[i]);
        parent --;
        a[parent].push_back(i);
        a[i].push_back(parent);
    }
}

// returns true if subtree of u contains t
bool getVertsAlongPath(int u, int parent) {
    if(u == t) {
        alongPath[u] = true;
        return true;
    }

    for(int v : a[u]) {
        if(v == parent)
            continue;

        if(getVertsAlongPath(v, u)) {
            alongPath[u] = true;
            return true;
        }
    }

    alongPath[u] = false;
    return false;
}

multiset<long long> ms;
priority_queue<
    pair<long long, long long>,
    vector<pair<long long, long long> >,
    greater<pair<long long, long long> > > pq; // (val, cost)
/*
    - Priority Queue contains val and cost pairs of only those
    vertices which are not decendents of current vertex and
    have distance less than or equal to m
    - Multiset contains cost values of the same vertices whose
    information is stored in the priority queue
*/

void computeValNonPathBranch(
    int u,
    int parent,
    int rootVal,
    int dist,
    int rootCost
) {
    cout << u << " " << rootCost << "+_+_++_+\n";
    val[u] = rootVal - dist;
    if(c[u] > 0) {
        pq.push({val[u], rootCost + c[u]});
        ms.insert(rootCost + c[u]);
    }

    for(int v : a[u]) {
        if(parent == v)
            continue;
        computeValNonPathBranch(v, u, rootVal, dist + 1, rootCost);
    }
}

void computeDP(int u, int parent) {
    while(!pq.empty() && pq.top().first < val[u] - m) {
        cout << u << " " << val[u] << " " << pq.top().first << " |||| ";
        pair<long long, long long> remove = pq.top();
        pq.pop();
        multiset<long long>::iterator it = ms.find(remove.second);
        cout << remove.second << "\n";
        ms.erase(it);
    }
    cout << u << " " << val[u] << " " << pq.top().first <<" || ";

    if(ms.empty())
        return;

    dp[u] = *ms.begin();

    cout << dp[u] << "\n";

    if(u == t)
        return;

    int pathChildIdx = -1;
    for(int v : a[u]) {
        if(v == parent)
            continue;
        else if(alongPath[v])
            pathChildIdx = v;
        else
            computeValNonPathBranch(v, u, val[u], 1, dp[u]);
    }

    if(u != s && c[u] > 0) {
        pq.push({val[u], dp[u] + c[u]});
        ms.insert(dp[u] + c[u]);
    }

    val[pathChildIdx] = val[u] + 1;
    computeDP(pathChildIdx, u);
}

long long solve() {
    for(int i = 0;i < n;i++) {
        dp[i] = -1;
        val[i] = INF;
        alongPath[i] = false;
    }

    (void)getVertsAlongPath(s, -1);

    ms.clear();
    while(!pq.empty())
        pq.pop();

    val[s] = 0;
    pq.push({0, 0});
    ms.insert(0);
    computeDP(s, -1);

    return dp[t];
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